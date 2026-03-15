from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():

    dynamic_controller = Node(
        package="dynamic_controller",
        executable="dynamic_controller",
        name="dynamic_controller"
        parameters=[
            {"use_sim_time": True},
            {"with_redundancy": False},
            {"linear_k": 100.0},
            {"linear_d": 10.0},
            {"joint_k": 100.0},
            {"joint_d": 10.0},
            {"urdf_file_name": "$(find-pkg-share kortex_description)/robots/gen3.urdf"},
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
    potential_field_task_path = [launch_ros.substitutions.FindPackageShare("potential_field"), '/launch/potential_field_task.launch.xml']
    potential_field_joint_path = [launch_ros.substitutions.FindPackageShare("potential_field"), '/launch/potential_field_joint.launch.xml']

    potential_field_launch = launch.actions.IncludeLaunchDescription(
        launch_xml.launch_description_sources.XMLLaunchDescriptionSource(potential_field_task_path),
        launch_xml.launch_description_sources.XMLLaunchDescriptionSource(potential_field_joint_path)
    )
