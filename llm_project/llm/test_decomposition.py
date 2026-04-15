import argparse
import json
from pathlib import Path

import torch

from llm_functions import MyApproach

# Always next to this script (matches executor default: llm_project/llm/task.json).
TASK_JSON_OUT = Path(__file__).resolve().parent / "task.json"

def main():
    parser = argparse.ArgumentParser(description="Test task decomposition")
    parser.add_argument("--task", type=str, default="pick the cup", help="Instruction to test")
    args = parser.parse_args()
    #model_name = "Qwen/Qwen2.5-1.5B-Instruct"
    #model_name = "meta-llama/Llama-3.2-1B-Instruct"
    model_name = "HuggingFaceTB/SmolLM2-1.7B-Instruct"
    device = "cuda" if torch.cuda.is_available() else "cpu"
    
    print(f"Loading {model_name} on {device}...")
    my_approach = MyApproach(model_name, device=device)

    # Instruction to test
    # "put the blue cube in the blue bowl"
    instruction = args.task
    
    # System context asking explicitly for JSON (use the best prompt from the analysis)
    SYSTEM_BASE = """You are a robot planner. Decompose the given instruction into a sequence of robot actions.

    AVAILABLE ACTIONS — you MUST use ONLY these, spelled exactly as shown:
    • move_pose
    • close_gripper
    • open_gripper

    OUTPUT FORMAT — output ONLY a valid JSON object, no extra text, no markdown fences:
    {
    "step_1": {
        "action": "<one action from the list above>",
        "object_a": "<object being manipulated, or null>",
        "object_b": "<target/reference object, or null>",
        "spatial_relation": "<spatial relation, or null>"
    },
    "step_2": { ... }
    }
    ALLOWED VALUES:
    • spatial_relation: "above", "left_of", "right_of", "behind", "in_front_of", or null
    • object_a / object_b: "cube", "cup", "table", "neutral_pose", or null

    SEQUENCING RULES:
    1. Always move to the object before gripping it.
    2. After gripping, ALWAYS move to neutral_pose before moving to the destination.
    3. When placing, move ABOVE the destination before opening the gripper.
    4. Never go to the destination before picking the object up.
    5. If only pushing (no grip), move to object then move to destination — no gripper steps.
    """

        
    EXAMPLE_1 = """
    EXAMPLE:
    Instruction: push the cube to the left
    Output JSON:
    {
    "step_1": {"action": "move_pose",    "object_a": null,   "object_b": "cube", "spatial_relation": null},
    "step_2": {"action": "move_pose",    "object_a": null,   "object_b": "cube", "spatial_relation": "left_of"}
    }"""

    EXAMPLE_2 = """
    EXAMPLE:
    Instruction: put the cube in the cup
    Output JSON:
    {
    "step_1": {"action": "move_pose",     "object_a": null,   "object_b": "cube",         "spatial_relation": null},
    "step_2": {"action": "close_gripper", "object_a": "cube", "object_b": null,            "spatial_relation": null},
    "step_3": {"action": "move_pose",     "object_a": "cube", "object_b": "neutral_pose",  "spatial_relation": null},
    "step_4": {"action": "move_pose",     "object_a": "cube", "object_b": "cup",           "spatial_relation": "above"},
    "step_5": {"action": "open_gripper",  "object_a": "cube", "object_b": "cup",           "spatial_relation": null}
    }"""

    EXAMPLE_3 = """
    EXAMPLE:
    Instruction: move the cube to the right of the cup
    Output JSON:
    {
    "step_1": {"action": "move_pose",     "object_a": null,   "object_b": "cube",         "spatial_relation": null},
    "step_2": {"action": "close_gripper", "object_a": "cube", "object_b": null,            "spatial_relation": null},
    "step_3": {"action": "move_pose",     "object_a": "cube", "object_b": "neutral_pose",  "spatial_relation": null},
    "step_4": {"action": "move_pose",     "object_a": "cube", "object_b": "cup",           "spatial_relation": "right_of"},
    "step_5": {"action": "open_gripper",  "object_a": "cube", "object_b": "cup",           "spatial_relation": null}
    }"""

    context = SYSTEM_BASE + EXAMPLE_1 + EXAMPLE_2 + EXAMPLE_3
    
    query = f"Instruction: {instruction}\nOutput JSON:"

    print(f"\nExecuting query for instruction: '{instruction}'")
    
    # generate_response is defined in llm_functions.py
    result = my_approach.generate_response(context, query, verbose=False)
    
    print("\n--- Raw Model Output ---")
    print(result)
    
    # Attempting to parse the json specifically
    print("\n--- JSON Parsing Test ---")
    try:
        # Clean up any potential markdown formatting the model might add
        clean_result = result.replace("```json", "").replace("```", "").strip()
        parsed_json = json.loads(clean_result)
        print("Success! Valid JSON detected:")
        print(json.dumps(parsed_json, indent=2))
        
        with open(TASK_JSON_OUT, "w", encoding="utf-8") as f:
            json.dump(parsed_json, f, indent=2)
        print(f"Output successfully saved to {TASK_JSON_OUT}")
    except json.JSONDecodeError:
        print("Warning: The model's output was not perfectly formatted as JSON.")

if __name__ == "__main__":
    main()
