import launch

import launch_ros.actions 
from launch.actions import DeclareLaunchArgument, ExecuteProcess, RegisterEventHandler
from launch.event_handlers import OnProcessExit
from launch.substitutions import FindExecutable, LaunchConfiguration
from launch.substitutions import PathJoinSubstitution
import launch.launch_description_sources
from ament_index_python.packages import get_package_share_directory
from launch_ros.substitutions import FindPackageShare
import os
def generate_launch_description():
    
    # Declare the argument in the parent
    control_orient_arg = DeclareLaunchArgument('control_orientation', default_value='true')
    task_arg = DeclareLaunchArgument('task', default_value='pick the cup')
    llm_python_arg = DeclareLaunchArgument(
        'llm_python',
        # If you `source <venv>/bin/activate` before launching, this will resolve to the venv python.
        default_value=os.environ.get("VIRTUAL_ENV") + "/bin/python3.10",
        #default_value='/home/aidan/code-554/applied-robotics-w2026/llm_project/.llm_venv/bin/python3.10',
    )

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

    decompose_task = ExecuteProcess(
        cmd=[
            LaunchConfiguration('llm_python'),
            PathJoinSubstitution([FindPackageShare('llm_project'), 'llm', 'test_decomposition.py']),
            '--task',
            LaunchConfiguration('task'),
        ],
        output='screen',
    )

    start_executor_after_decompose = RegisterEventHandler(
        OnProcessExit(
            target_action=decompose_task,
            on_exit=[executor],
        )
    )
       
    ld = launch.LaunchDescription()
    ld.add_action(control_orient_arg)
    ld.add_action(task_arg)
    ld.add_action(llm_python_arg)
    ld.add_action(main_program)    
    ld.add_action(joint_velocity_controller)
    ld.add_action(highlevel_controller)
    ld.add_action(decompose_task)
    ld.add_action(start_executor_after_decompose)
    return ld