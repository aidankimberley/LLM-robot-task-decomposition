sudo apt install ros-jazzy-gz-ros2-control
sudo apt install ros-jazzy-ros-gz

colcon build --packages-up-to kortex_sim

ros2 launch kortex_sim a3.launch.py


