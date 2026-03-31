from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition, UnlessCondition

def generate_launch_description():
    
    declare_with_redundancy = DeclareLaunchArgument(
        'control_orientation',
        default_value='true',
        description='Whether to control orientation'
    )

    arg_control_orientation = LaunchConfiguration('control_orientation')


    # potential_field_action_server = Node(
    #     package="potential_field",
    #     executable="potential_field_action_server",
    #     name="potential_field_action_server",
    #     #arguments=["--ros-args", "--log-level", "debug"],
    #     parameters=[
    #         {"use_sim_time": True},
    #         {"with_redundancy": True},
    #         {"robot_pose_topic": "/gen3/feedback/pose"},
    #         {"target_twist_topic": "/gen3/reference/twist"},
    #         {"k_att": 5.0},
    #         {"done_translation": 0.05},
    #         {"done_orientation": 0.01},
    #         {"timeout_s": 5.0},
    #         {"use_orientation": arg_control_orientation},
    #         {"action_name": "/planner/move_pose"},
    #     ]
    # )
    potential_field_action_server = IncludeLaunchDescription(
        AnyLaunchDescriptionSource(
            PathJoinSubstitution([FindPackageShare("potential_field"), "launch", "potential_field_action_server.launch.xml"])
        ),
        condition=IfCondition(arg_control_orientation),
    )

    kinematic_controller_6d = IncludeLaunchDescription(
        AnyLaunchDescriptionSource(
            PathJoinSubstitution([FindPackageShare("kinematic_controller"), "launch", "6d.launch.xml"])
        )
        ,
        condition=IfCondition(arg_control_orientation),
    )

    kinematic_controller_3d = IncludeLaunchDescription(
        AnyLaunchDescriptionSource(
            PathJoinSubstitution([FindPackageShare("kinematic_controller"), "launch", "3d.launch.xml"])
        ),
        condition=UnlessCondition(arg_control_orientation),
    )

    return LaunchDescription([
        declare_with_redundancy,
        kinematic_controller_6d,
        kinematic_controller_3d,
        potential_field_action_server,
    ])