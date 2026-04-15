cmake_minimum_required(VERSION 3.5)
project(kortex_sim)

find_package(ament_cmake REQUIRED)

find_package(rclcpp REQUIRED)


install(DIRECTORY config launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
