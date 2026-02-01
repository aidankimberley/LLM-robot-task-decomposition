cmake_minimum_required(VERSION 3.8)
project(potential_field)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(highlevel_interfaces REQUIRED)
find_package(Eigen3 REQUIRED)

# Build executable (not library)
add_executable(potential_field_2d
    src/potential_field_2d.cpp
    src/PotentialField2D.cpp
    
)

add_executable(potential_field_joint
    src/PotentialFieldJoint.cpp
    src/potential_field_joint.cpp
)

ament_target_dependencies(potential_field_2d
    rclcpp
    geometry_msgs
    std_msgs
    highlevel_interfaces
)

ament_target_dependencies(potential_field_joint
    rclcpp
    geometry_msgs
    std_msgs
    highlevel_interfaces
)

target_include_directories(potential_field_2d PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    ${EIGEN3_INCLUDE_DIR}
)

target_include_directories(potential_field_joint PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    ${EIGEN3_INCLUDE_DIR}
)

# Install executables
install(TARGETS potential_field_2d potential_field_joint
    DESTINATION lib/${PROJECT_NAME}
)

# Install header files
install(DIRECTORY include/
    DESTINATION include
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
