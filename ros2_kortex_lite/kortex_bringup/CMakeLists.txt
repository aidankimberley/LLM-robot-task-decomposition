cmake_minimum_required(VERSION 3.5)
project(kortex_bringup)

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclcpp REQUIRED)
find_package(controller_manager_msgs REQUIRED)
find_package(ros_gz_interfaces REQUIRED)
find_package(sensor_msgs REQUIRED)


add_executable(gazebo_spawner_manager src/gazebo_spawner_manager.cpp)
ament_target_dependencies(gazebo_spawner_manager rclcpp controller_manager_msgs ros_gz_interfaces sensor_msgs)
install(TARGETS gazebo_spawner_manager DESTINATION lib/${PROJECT_NAME})

#add_executable(startup_manager src/startup_manager.cpp)
#ament_target_dependencies(startup_manager rclcpp controller_manager_msgs ros_gz_interfaces )
#install(TARGETS startup_manager
#    DESTINATION lib/${PROJECT_NAME}/
#)

install(DIRECTORY config launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
