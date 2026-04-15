cmake_minimum_required(VERSION 3.5)
project(kortex_controller)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(Eigen3 REQUIRED)


########### Joint Velocity Controller
add_executable(joint_velocity_controller src/joint_velocity_controller.cpp)
ament_target_dependencies(joint_velocity_controller rclcpp std_msgs sensor_msgs rclcpp)
target_link_libraries(joint_velocity_controller Eigen3::Eigen)

install(TARGETS joint_velocity_controller
    DESTINATION lib/${PROJECT_NAME}/
)

ament_package()
