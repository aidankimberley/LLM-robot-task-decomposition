#!/usr/bin/env python3
"""ROS 2 executor: JSON task steps → PoseCommand + ParallelGripperCommand."""

from __future__ import annotations

import argparse
import json
import math
import re
import sys
import os
import time
from pathlib import Path
from typing import Any

import rclpy
from action_msgs.msg import GoalStatus
from control_msgs.action import ParallelGripperCommand
from highlevel_interfaces.action import PoseCommand
from rclpy.action import ActionClient
from rclpy.node import Node
from sensor_msgs.msg import JointState


# --- Action server names ---
DEFAULT_POSE_ACTION = "/planner/move_pose"
DEFAULT_GRIPPER_ACTION = "/gripper_controller/gripper_cmd"

# Small pause between sequential actions (seconds).
INTER_ACTION_SLEEP_S = 0.5

# Wait before doing anything (seconds).
STARTUP_SLEEP_S = 1.0

# --- Gripper joint command (parallel gripper; tune to your URDF) ---
GRIPPER_JOINTS = ["right_finger_bottom_joint"]
GRIPPER_OPEN = [0.0]
GRIPPER_CLOSED = [0.65]

# --- Hard-coded world poses (base / planning frame). Replace with Gazebo later. ---
# z must stay within PotentialFieldActionServer limits (~0.01–0.8) if you use that planner.
HARDCODED_OBJECT_POSES: dict[str, dict[str, float]] = {
    "cube": {
        "x": 0.50,
        "y": 0.00,
        "z": 0.35,
        "roll": math.pi,
        "pitch": 0.0,
        "yaw": 0.0,
    },
    "table": {
        "x": 0.50,
        "y": 0.0,
        "z": 0.25,
        "roll": math.pi,
        "pitch": 0.0,
        "yaw": 0.0,
    },
    "cup": {
        "x": 0.45,
        "y": 0.20,
        "z": 0.42,
        "roll": math.pi,
        "pitch": 0.0,
        "yaw": 0.0,
    },
    "neutral_pose": {
        "x": 0.4,
        "y": 0.0,
        "z": 0.60-0.12, # note approach dz will be added
        "roll": math.pi,
        "pitch": 0.0,
        "yaw": 0.0,
    }
}

# Extra height above object / table for approach & place (meters).
_APPROACH_DZ = 0.12
_PLACE_DZ = 0.10
# Spatial offsets: base frame has +x = forward, +y = left (REP-103 style).
_ABOVE_EXTRA_DZ = 0.10  # added on top of approach when relation is "above"
_OFFSET_FRONT = 0.12  # +x = in_front_of
_OFFSET_SIDE = 0.15  # +y = left_of, −y = right_of
_CLEARANCE_DZ = 0.06  # small +z for lateral/front/behind goals to clear the anchor


def _normalize_spatial_relation(rel: Any) -> str:
    """Map JSON / CLI spatial_relation to a canonical token."""
    if rel is None:
        return "null"
    if isinstance(rel, str):
        s = rel.strip().lower().replace("-", "_")
        while "  " in s:
            s = s.replace("  ", " ")
        s = s.replace(" ", "_")
        aliases = {
            "none": "null",
            "": "null",
            "infrontof": "in_front_of",
            "in_front": "in_front_of",
            "front": "in_front_of",
            "back": "behind",
            "rear": "behind",
            "left": "left_of",
            "right": "right_of",
        }
        return aliases.get(s, s)
    return "null"


def _step_sort_key(name: str) -> tuple[int, str]:
    m = re.match(r"^step_(\d+)$", name.strip(), re.IGNORECASE)
    if m:
        return (int(m.group(1)), name)
    return (10**9, name)


def load_task_steps(path: Path) -> list[tuple[str, dict[str, Any]]]:
    data = json.loads(path.read_text(encoding="utf-8"))
    if not isinstance(data, dict):
        raise ValueError("Task JSON root must be an object")
    ordered = sorted(data.items(), key=lambda kv: _step_sort_key(kv[0]))
    out: list[tuple[str, dict[str, Any]]] = []
    for step_id, step in ordered:
        if not isinstance(step, dict):
            raise ValueError(f"{step_id}: step must be an object")
        out.append((step_id, step))
    return out


def _copy_pose(src: dict[str, float]) -> dict[str, float]:
    return {
        "x": float(src["x"]),
        "y": float(src["y"]),
        "z": float(src["z"]),
        "roll": float(src["roll"]),
        "pitch": float(src["pitch"]),
        "yaw": float(src["yaw"]),
    }


def _pose_from_anchor_and_relation(obj_b: str, relation: str) -> dict[str, float]:
    """
    EE goal from anchor object_b pose and spatial_relation.
    Axes: +x forward, +y left, +z up.
    """
    base = HARDCODED_OBJECT_POSES.get(obj_b)
    if base is None:
        raise KeyError(f"No hard-coded pose for object {obj_b!r}")
    p = _copy_pose(base)

    if relation == "null":
        p["z"] = min(p["z"] + _APPROACH_DZ, 0.75)
        return p

    if relation == "above":
        p["z"] = min(p["z"] + _APPROACH_DZ + _ABOVE_EXTRA_DZ, 0.75)
        return p

    if relation == "in_front_of":
        p["x"] += _OFFSET_FRONT
        p["z"] = min(p["z"] + _CLEARANCE_DZ, 0.75)
        return p

    if relation == "behind":
        p["x"] -= _OFFSET_FRONT
        p["z"] = min(p["z"] + _CLEARANCE_DZ, 0.75)
        return p

    if relation == "left_of":
        p["y"] += _OFFSET_SIDE
        p["z"] = min(p["z"] + _CLEARANCE_DZ, 0.75)
        return p

    if relation == "right_of":
        p["y"] -= _OFFSET_SIDE
        p["z"] = min(p["z"] + _CLEARANCE_DZ, 0.75)
        return p

    if relation == "on":
        # Hover over support surface without a carried object (e.g. touch-down pose).
        p["z"] = min(p["z"] + _PLACE_DZ, 0.75)
        return p

    raise ValueError(f"Unknown spatial_relation {relation!r}")


def pose_for_move_step(step: dict[str, Any]) -> dict[str, float]:
    """Turn a move_to / move_pose step into a PoseCommand goal dict."""
    obj_a = step.get("object_a")
    obj_b = step.get("object_b")
    rel = _normalize_spatial_relation(step.get("spatial_relation"))

    if obj_b is None:
        raise ValueError(f"move step needs object_b: {step!r}")

    # Place object_a onto support object_b (keep previous semantics).
    if rel == "on" and obj_a is not None:
        surf = HARDCODED_OBJECT_POSES.get(obj_b)
        if surf is None:
            raise KeyError(f"No hard-coded pose for object {obj_b!r}")
        p = _copy_pose(surf)
        p["z"] = min(p["z"] + _PLACE_DZ, 0.75)
        return p

    # EE relative to object_b: null, above, in_front_of, behind, left_of, right_of, on (no obj_a).
    allowed = ("null", "above", "in_front_of", "behind", "left_of", "right_of", "on")
    if rel not in allowed:
        raise ValueError(
            f"Unsupported spatial_relation {rel!r}; expected one of {allowed}"
        )
    return _pose_from_anchor_and_relation(obj_b, rel)


def resolve_default_task_path() -> Path | None:
    try:
        from ament_index_python.packages import get_package_share_directory

        share = Path(get_package_share_directory("llm_project"))
        candidate = share / "llm" / "task.json"
        if candidate.is_file():
            return candidate
    except Exception:
        pass
    dev = Path(__file__).resolve().parent / "llm" / "task.json"
    if dev.is_file():
        return dev
    return None


class ExecutorNode(Node):
    def __init__(self, pose_action: str, gripper_action: str) -> None:
        super().__init__("executor")
        self._pose_client = ActionClient(self, PoseCommand, pose_action)
        self._gripper_client = ActionClient(self, ParallelGripperCommand, gripper_action)

    def send_pose_goal(self, pose: dict[str, float] | None = None) -> bool:
        if pose is None:
            pose = HARDCODED_OBJECT_POSES["cup"]
            pose = _copy_pose(pose)
            pose["z"] = min(pose["z"] + _APPROACH_DZ, 0.75)

        if not self._pose_client.wait_for_server(timeout_sec=10.0):
            self.get_logger().error(
                "PoseCommand server not available (10s). Check planner / action name."
            )
            return False

        goal = PoseCommand.Goal()
        for key in ("x", "y", "z", "roll", "pitch", "yaw"):
            setattr(goal, key, float(pose[key]))

        self.get_logger().info(
            f"PoseCommand: x={goal.x:.3f} y={goal.y:.3f} z={goal.z:.3f} "
            f"rpy=({goal.roll:.3f}, {goal.pitch:.3f}, {goal.yaw:.3f})"
        )

        send_future = self._pose_client.send_goal_async(
            goal, feedback_callback=self._pose_feedback_cb
        )
        rclpy.spin_until_future_complete(self, send_future)
        gh = send_future.result()
        if gh is None or not gh.accepted:
            self.get_logger().error("PoseCommand goal rejected or failed to send")
            return False

        result_future = gh.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)
        wr = result_future.result()
        result = wr.result
        status_name = {
            GoalStatus.STATUS_SUCCEEDED: "SUCCEEDED",
            GoalStatus.STATUS_ABORTED: "ABORTED",
            GoalStatus.STATUS_CANCELED: "CANCELED",
        }.get(wr.status, f"status={wr.status}")

        self.get_logger().info(
            f"PoseCommand finished: {status_name} success={result.success} message={result.message!r}"
        )
        return wr.status == GoalStatus.STATUS_SUCCEEDED

    def send_gripper_goal(self, positions: list[float]) -> bool:
        if not self._gripper_client.wait_for_server(timeout_sec=10.0):
            self.get_logger().error(
                "ParallelGripperCommand server not available (10s). "
                "Check gripper controller / action name."
            )
            return False

        goal = ParallelGripperCommand.Goal()
        goal.command = JointState()
        goal.command.name = list(GRIPPER_JOINTS)
        goal.command.position = [float(p) for p in positions]

        self.get_logger().info(
            f"Gripper: joints={list(goal.command.name)} position={list(goal.command.position)}"
        )

        send_future = self._gripper_client.send_goal_async(
            goal, feedback_callback=self._gripper_feedback_cb
        )
        rclpy.spin_until_future_complete(self, send_future)
        gh = send_future.result()
        if gh is None or not gh.accepted:
            self.get_logger().error("Gripper goal rejected or failed to send")
            return False

        result_future = gh.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)
        wr = result_future.result()
        result = wr.result
        status_name = {
            GoalStatus.STATUS_SUCCEEDED: "SUCCEEDED",
            GoalStatus.STATUS_ABORTED: "ABORTED",
            GoalStatus.STATUS_CANCELED: "CANCELED",
        }.get(wr.status, f"status={wr.status}")

        self.get_logger().info(
            f"Gripper finished: {status_name} stalled={result.stalled} reached_goal={result.reached_goal}"
        )
        return wr.status == GoalStatus.STATUS_SUCCEEDED

    def run_task(self, task_path: Path) -> None:
        steps = load_task_steps(task_path)
        self.get_logger().info(f"Loaded {len(steps)} steps from {task_path}")

        for i, (step_id, step) in enumerate(steps):
            action = step.get("action")
            if action is None:
                raise ValueError(f"{step_id}: missing action")

            action_norm = str(action).lower().replace("-", "_")
            self.get_logger().info(f"--- {step_id}: {action_norm} {step}")

            if action_norm in ("move_to", "move_pose"):
                pose = pose_for_move_step(step)
                if not self.send_pose_goal(pose):
                    self.get_logger().error(f"Stopping after failure in {step_id}")
                    return
            elif action_norm == "close_gripper":
                if not self.send_gripper_goal(GRIPPER_CLOSED):
                    self.get_logger().error(f"Stopping after failure in {step_id}")
                    return
            elif action_norm == "open_gripper":
                if not self.send_gripper_goal(GRIPPER_OPEN):
                    self.get_logger().error(f"Stopping after failure in {step_id}")
                    return
            else:
                raise ValueError(f"{step_id}: unknown action {action!r}")

            if i != len(steps) - 1:
                _sleep_sim(self, INTER_ACTION_SLEEP_S, label="Inter-action sleep")

        self.get_logger().info("Task completed.")

    def _pose_feedback_cb(self, msg) -> None:
        fb = msg.feedback
        self.get_logger().info(
            f"Pose feedback: d_trans={fb.distance_translation:.4f} "
            f"d_rot={fb.distance_orientation:.4f} t={fb.time_elapsed:.2f}s"
        )

    def _gripper_feedback_cb(self, msg) -> None:
        st = msg.feedback.state
        pos = list(st.position) if st.position else []
        self.get_logger().info(f"Gripper feedback: position={pos}")


def _sleep_sim(node: Node, seconds: float, *, label: str) -> None:
    """Sleep for `seconds` using ROS time (/clock)."""
    if seconds <= 0:
        return

    # Wait for /clock to start advancing (sim time).
    start_wall = time.monotonic()
    last_now_ns = node.get_clock().now().nanoseconds
    while (time.monotonic() - start_wall) < 30.0:
        rclpy.spin_once(node, timeout_sec=0.1)
        now_ns = node.get_clock().now().nanoseconds
        if now_ns != 0 and now_ns != last_now_ns:
            break
        last_now_ns = now_ns

    now_ns = node.get_clock().now().nanoseconds
    if now_ns == 0:
        node.get_logger().warn(
            f"{label}: /clock not active; skipping sleep to avoid wall-time delay"
        )
        return

    target_ns = now_ns + int(seconds * 1e9)
    node.get_logger().info(f"{label}: sleeping {seconds:.1f}s (sim time)")
    while rclpy.ok() and node.get_clock().now().nanoseconds < target_ns:
        rclpy.spin_once(node, timeout_sec=0.1)
    node.get_logger().info(f"{label}: done")


def _run_demo(node: ExecutorNode) -> None:
    p = _copy_pose(HARDCODED_OBJECT_POSES["cup"])
    p["z"] = min(p["z"] + _APPROACH_DZ, 0.75)
    node.send_pose_goal(p)
    _sleep_sim(node, INTER_ACTION_SLEEP_S, label="Inter-action sleep")
    node.send_gripper_goal(GRIPPER_OPEN)


def main(argv: list[str] | None = None) -> None:
    argv = argv if argv is not None else sys.argv
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "pose_action",
        nargs="?",
        default=DEFAULT_POSE_ACTION,
        help=f"PoseCommand action name (default: {DEFAULT_POSE_ACTION})",
    )
    parser.add_argument(
        "--gripper-action",
        default=DEFAULT_GRIPPER_ACTION,
        help=f"ParallelGripperCommand action name (default: {DEFAULT_GRIPPER_ACTION})",
    )
    parser.add_argument(
        "--task",
        type=Path,
        default=None,
        help="JSON task file (default: llm/task.json from package share or source tree)",
    )
    parser.add_argument(
        "--demo",
        action="store_true",
        help="Ignore --task; run a fixed pose + open-gripper smoke test",
    )
    parser.add_argument(
        "--pose-only",
        action="store_true",
        help="With --demo: only pose",
    )
    parser.add_argument(
        "--gripper-only",
        action="store_true",
        help="With --demo: only gripper (open)",
    )
    parser.add_argument(
        "--startup-sleep",
        type=float,
        default=STARTUP_SLEEP_S,
        help=f"Seconds to wait before doing anything (default: {STARTUP_SLEEP_S})",
    )

    # IMPORTANT: when launched via `ros2 launch`, ROS injects arguments like:
    #   --ros-args -r __node:=executor --params-file /tmp/launch_params_XXXX
    # If we let argparse see those, it can mistakenly consume tokens like
    # "__node:=executor" as our positional `pose_action`, breaking rclpy parsing.
    ros_args_idx = None
    for i, tok in enumerate(argv[1:], start=1):
        if tok == "--ros-args":
            ros_args_idx = i
            break
    user_argv = argv[1:ros_args_idx] if ros_args_idx is not None else argv[1:]
    ros_argv = argv[ros_args_idx:] if ros_args_idx is not None else []

    args = parser.parse_args(user_argv)
    rclpy.init(args=[argv[0]] + ros_argv)

    if args.demo and args.pose_only and args.gripper_only:
        parser.error("Use at most one of --pose-only / --gripper-only with --demo")

    task_path = args.task
    if not args.demo:
        if task_path is None:
            task_path = resolve_default_task_path()
        else:
            task_path = task_path.expanduser().resolve()
        if task_path is None or not task_path.is_file():
            parser.error(
                "No task file found. Pass --task PATH, install llm/task.json via colcon, "
                "or run from source with llm/task.json present."
            )

    node = ExecutorNode(args.pose_action, args.gripper_action)
    try:
        node.get_logger().info(f"Executor starting (pid={os.getpid()})")
        _sleep_sim(node, float(args.startup_sleep), label="Startup sleep")
        if args.demo:
            if args.gripper_only:
                node.send_gripper_goal(GRIPPER_OPEN)
            elif args.pose_only:
                p = _copy_pose(HARDCODED_OBJECT_POSES["cup"])
                p["z"] = min(p["z"] + _APPROACH_DZ, 0.75)
                node.send_pose_goal(p)
            else:
                _run_demo(node)
        else:
            assert task_path is not None
            node.run_task(task_path)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
