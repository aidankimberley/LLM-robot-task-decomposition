# Copyright (c) 2021 PickNik, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Author: Marq Rasmussen

import os
from ament_index_python.packages import get_package_prefix
from launch import LaunchDescription
from launch.actions import (
    AppendEnvironmentVariable,
    DeclareLaunchArgument,
    IncludeLaunchDescription,
    OpaqueFunction,
    RegisterEventHandler,
)
from launch.event_handlers import OnProcessExit
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.conditions import IfCondition, UnlessCondition
from launch.substitutions import (
    Command,
    FindExecutable,
    LaunchConfiguration,
    PathJoinSubstitution,
)
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
import launch.event_handlers

def launch_setup(context, *args, **kwargs):

    # Initialize Arguments
    sim_gazebo = LaunchConfiguration("sim_gazebo")
    robot_type = LaunchConfiguration("robot_type")
    dof = LaunchConfiguration("dof")
    vision = LaunchConfiguration("vision")
    
    # General arguments
    controllers_file = LaunchConfiguration("controllers_file")
    description_package = LaunchConfiguration("description_package")
    description_file = LaunchConfiguration("description_file")
    robot_name = LaunchConfiguration("robot_name")
    prefix = LaunchConfiguration("prefix")
    joint_effort_controller = LaunchConfiguration("joint_effort_controller")
    launch_rviz = LaunchConfiguration("launch_rviz")
    use_sim_time = LaunchConfiguration("use_sim_time")
    gripper = LaunchConfiguration("gripper")

    robot_controllers = PathJoinSubstitution(
        [
            FindPackageShare(description_package),
            "arms/" + robot_type.perform(context) + "/" + dof.perform(context) + "dof/config",
            controllers_file,
        ]
    )

    robot_description_content = Command(
        [
            PathJoinSubstitution([FindExecutable(name="xacro")]),
            " ",
            PathJoinSubstitution(
                [FindPackageShare(description_package), "robots", description_file]
            ),
            " ",
            "robot_ip:=xxx.yyy.zzz.www",
            " ",
            "name:=",
            robot_name,
            " ",
            "arm:=",
            robot_type,
            " ",
            "dof:=",
            dof,
            " ",
            "vision:=",
            vision,
            " ",
            "prefix:=",
            prefix,
            " ",
            "sim_gazebo:=",
            sim_gazebo,
            " ",
            "simulation_controllers:=",
            robot_controllers,
            " ",
            "gripper:=",
            gripper,
            " ",
        ]
    )

    robot_description = {"robot_description": robot_description_content.perform(context)}

    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        output="both",
        parameters=[
            robot_description,
            {"use_sim_time": use_sim_time},
        ],
    )
  
    robot_model = robot_type.perform(context)
    is_gen3_lite = "false"
    if robot_model == "gen3_lite":
        is_gen3_lite = "true"

    gz_spawn_entity = Node(
        package="ros_gz_sim",
        executable="create",
        output="screen",
        arguments=[
            "-string",
            robot_description_content,
            "-name",
            robot_name,
            "-allow_renaming",
            "true",
            "-x",
            "0.0",
            "-y",
            "0.0",
            "-z",
            "0.0",
            "-R",
            "0.0",
            "-P",
            "0.0",
            "-Y",
            "0.0",
        ],
        condition=IfCondition(sim_gazebo),
    )

    gz_launch_description = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([FindPackageShare("ros_gz_sim"), "/launch/gz_sim.launch.py"]),
        launch_arguments={
            "gz_args": "-v 3 empty.sdf", # --physics-engine gz-physics-bullet-featherstone-plugin",
        #    "pause": "True",
        }.items(),        
        condition=IfCondition(sim_gazebo)        
    )
   
     # Bridge
    ros_gazebo_bridge = Node(
        package="ros_gz_bridge",
        name="ros_gazebo_bridge",
        executable="parameter_bridge",
        arguments=[
            "/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock",
            "/world/empty/control@ros_gz_interfaces/srv/ControlWorld@gz.msgs.WorldControl@gz.msgs.Boolean"
        ],
        output="screen",
    )
    
    gazebo_spawner_manager = Node(
        package="kortex_bringup",
        executable="gazebo_spawner_manager",
        name="gazebo_spawner_manager",
        output="screen",        
        arguments=['--ros-args', '--log-level', 'Debug', '--log-level', 'rcl:=Warn'],
        parameters=[
            {"emulate_tty": True}
        ],
    )

    nodes_to_start = [        
        gazebo_spawner_manager,
        robot_state_publisher_node,   
        ros_gazebo_bridge,
        gz_launch_description,
        gz_spawn_entity,     
    ]
    return nodes_to_start


def generate_launch_description():
    declared_arguments = []
    declared_arguments.append(
        DeclareLaunchArgument(
            "sim_gazebo",
            default_value="true",
            description="Use Gazebo for simulation",
        )
    )
    # Robot specific arguments
    declared_arguments.append(
        DeclareLaunchArgument(
            "robot_type",
            description="Type/series of robot.",
            choices=["gen3", "gen3_lite"],
            default_value="gen3",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "dof",
            description="DoF of robot.",
            choices=["6", "7"],
            default_value="7",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "vision",
            description="Use arm mounted realsense",
            choices=["true", "false"],
            default_value="false",
        )
    )
    # General arguments
    declared_arguments.append(
        DeclareLaunchArgument(
            "controllers_file",
            default_value="ros2_controllers_torque.yaml",
            description="YAML file with the controllers configuration.",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "description_package",
            default_value="kortex_description",
            description="Description package with robot URDF/XACRO files. Usually the argument \
        is not set, it enables use of a custom description.",
        )
    )
    
    declared_arguments.append(
        DeclareLaunchArgument(
            "description_file",
            default_value="kinova.urdf.xacro",
            description="URDF/XACRO description file with the robot.",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "robot_name",
            default_value="gen3",
            description="Robot name.",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "prefix",
            default_value='""',
            description="Prefix of the joint names, useful for \
        multi-robot setup. If changed than also joint names in the controllers' configuration \
        have to be updated.",
        )
    )
   
    declared_arguments.append(
        DeclareLaunchArgument(
            "joint_effort_controller",
            default_value="joint_effort_controller",
            description="Robot joint torque controller",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "use_sim_time",
            default_value="true",
            description="Use simulated clock",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "gripper",
            default_value="",
            choices=["robotiq_2f_85", "robotiq_2f_140", "gen3_lite_2f", ""],
            description="Gripper to use",
        )
    )
    return LaunchDescription(declared_arguments + [OpaqueFunction(function=launch_setup)])
