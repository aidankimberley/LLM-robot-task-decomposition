cmake_minimum_required(VERSION 3.8)
project(llm_project)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)


install(
  DIRECTORY
    launch
    worlds
    models
  DESTINATION share/${PROJECT_NAME}
)

install(
  DIRECTORY llm
  DESTINATION share/${PROJECT_NAME}
  PATTERN "__pycache__" EXCLUDE
  PATTERN "*.pyc" EXCLUDE
)

# Python node: installed as lib/<pkg>/executor → ros2 run llm_project executor
configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/executor.py"
  "${CMAKE_CURRENT_BINARY_DIR}/executor"
  COPYONLY
)
install(
  PROGRAMS "${CMAKE_CURRENT_BINARY_DIR}/executor"
  DESTINATION lib/${PROJECT_NAME}
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
