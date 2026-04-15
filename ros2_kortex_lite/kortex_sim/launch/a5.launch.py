import launch
import launch_ros.actions 
from launch.substitutions import LaunchConfiguration
import launch.launch_description_sources
from ament_index_python.packages import get_package_share_directory
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import PathJoinSubstitution
import launch_xml


def generate_launch_description():
   
    # main program
    main_path = [launch_ros.substitutions.FindPackageShare('kortex_bringup'), '/launch/torque_control.launch.py']
    main_program = launch.actions.IncludeLaunchDescription(
        launch.launch_description_sources.PythonLaunchDescriptionSource(main_path)
    )
    
    ld = launch.LaunchDescription()
    ld.add_action(main_program)        
    return ld