from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():

    dynamic_controller = Node(
        package="dynamic_controller",
        executable="dynamic_controller",
        name="dynamic_controller",
        parameters=[
            {"use_sim_time": True},
            {"with_redundancy": False},
            {"linear_k": 100.0},
            {"linear_d": 10.0},
            {"joint_k": 100.0},
            {"joint_d": 10.0},
            {"urdf_file_name": PathJoinSubstitution([FindPackageShare("kortex_description"), "robots", "gen3.urdf"])},
            {"joint_state_topic": "/joint_states"},
            {"end_pose_topic": "/gen3/feedback/pose"},
            {"end_twist_topic": "/gen3/feedback/twist"},
            {"reference_twist_topic": "/gen3/reference/twist"},
            {"reference_joint_position_topic": "/gen3/reference/position"},
            {"reference_joint_velocity_topic": "/gen3/reference/velocity"},
            {"reference_pose_topic": "/gen3/reference/pose"},
            {"joint_velocity_command_topic": "/gen3/command/joint_velocity"},
            {"reference_homing_velocity_topic": "/gen3/reference/velocity"},
        ]
    )

    potential_field_task = IncludeLaunchDescription(
        AnyLaunchDescriptionSource(
            PathJoinSubstitution([FindPackageShare("potential_field"), "launch", "potential_field_task.launch.xml"])
        )
    )

    potential_field_joint = IncludeLaunchDescription(
        AnyLaunchDescriptionSource(
            PathJoinSubstitution([FindPackageShare("potential_field"), "launch", "potential_field_joint.launch.xml"])
        )
    )

    return LaunchDescription([
        dynamic_controller,
        potential_field_task,
        potential_field_joint,
    ])
