### Task Decomposition for Robotics (Small LLMs)

This repo runs a Gazebo simulation + high-level controllers, takes a natural-language task prompt, decomposes it into a JSON plan using a small LLM, and then executes the plan via ROS 2 actions.

![Alt Text](short_llm_robot.gif)

### Prereqs

- **ROS 2 Jazzy** installed and sourced
- Gazebo / ROS-GZ tooling:

```bash
sudo apt install -y ros-jazzy-gz-ros2-control ros-jazzy-ros-gz
```

- **Python 3.10** available (used for the LLM venv in `llm_project/.venv/`)

### Setup

Clone this repo, then create the LLM virtual environment:

```bash
cd llm_project
python3.10 -m venv .venv
source .venv/bin/activate
pip install -e .
```

### Build (recommended workspace layout)

Create a separate ROS workspace (with a `src/` directory) and symlink this repo into it. From the workspace root:

```bash
colcon build --packages-up-to kortex_sim
source install/setup.bash
```

### Gazebo resources

Make sure Gazebo can find the description assets (adjust paths to your install):

```bash
export GZ_SIM_RESOURCE_PATH="$GZ_SIM_RESOURCE_PATH:<path_to_kortex_description>/models"
export GZ_SIM_RESOURCE_PATH="$GZ_SIM_RESOURCE_PATH:<path_to_kortex_description>/worlds"
```

### Run

The launch pipeline is:

1. start sim + controllers, 2) run LLM task decomposition, 3) run the executor.

In one terminal:

```bash
# ROS env (Jazzy)
source <your_ros_ws>/install/setup.bash

# LLM env (torch/transformers)
source /path/to/your/.venv/bin/activate

ros2 launch kortex_sim final.launch.py task:="pick up the cube"
```

Change the `task:=...` string to run different behaviors.