import launch
import launch_ros.actions 
from launch.substitutions import LaunchConfiguration
import launch.launch_description_sources
from ament_index_python.packages import get_package_share_directory
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import PathJoinSubstitution


def generate_launch_description():
   
    # main program
    main_path = [launch_ros.substitutions.FindPackageShare('kortex_bringup'), '/launch/a3.launch.py']
    main_program = launch.actions.IncludeLaunchDescription(
        launch.launch_description_sources.PythonLaunchDescriptionSource(main_path)
    )

    joint_velocity_controller = launch_ros.actions.Node(
        package="kortex_controller", 
        executable="joint_velocity_controller",
        name="joint_velocity_controller",
        output="screen",                
        parameters=[{'use_sim_time': True}]
    )
    

    ld = launch.LaunchDescription()
    ld.add_action(main_program)    
    ld.add_action(joint_velocity_controller)
    return ld