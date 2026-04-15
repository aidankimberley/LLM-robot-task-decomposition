import launch

import launch_ros.actions 
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
import launch.launch_description_sources
from ament_index_python.packages import get_package_share_directory
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    
    # Declare the argument in the parent
    control_orient_arg = DeclareLaunchArgument('control_orientation', default_value='true')

    # main program
    main_path = [launch_ros.substitutions.FindPackageShare('kortex_bringup'), '/launch/gripper.launch.py']
    main_program = launch.actions.IncludeLaunchDescription(
        launch.launch_description_sources.PythonLaunchDescriptionSource(main_path)
    )

     # kinematic controller and potential field planner
    highlevel_controller_path = [launch_ros.substitutions.FindPackageShare('highlevel_controller'), '/launch/a6.launch.py']
    highlevel_controller = launch.actions.IncludeLaunchDescription(
        launch.launch_description_sources.PythonLaunchDescriptionSource(highlevel_controller_path),
        launch_arguments={
            'control_orientation': LaunchConfiguration('control_orientation')
        }.items()
    )

    joint_velocity_controller = launch_ros.actions.Node(
        package="kortex_controller", 
        executable="joint_velocity_controller",
        name="joint_velocity_controller",
        output="screen",                
        parameters=[{'use_sim_time': True}]
    )

    executor = launch_ros.actions.Node(
        package="llm_project",
        executable="executor",
        name="executor",
        output="screen",
        parameters=[{'use_sim_time': True}]
    )
       
    ld = launch.LaunchDescription()
    ld.add_action(control_orient_arg)
    ld.add_action(main_program)    
    ld.add_action(joint_velocity_controller)
    ld.add_action(highlevel_controller)
    ld.add_action(executor)
    return ld