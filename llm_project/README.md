# LLM Project

This contains components for testing different LLMs and performing task decomposition tasks.

## Testing LLMs

The script `test_llms.py` is used to test and evaluate the language models. You can check the file at `llm_project/llm/test_llms.py` to see the logic.

To run the script, you can specify arguments such as the model, prompting strategy (shots), and specific tasks:

```bash
# Example 1: Run Qwen model with zero-shot prompting
python llm_project/llm/test_llms.py --models qwen --shots zero

# Example 2: Run all models with all shot configs and save to 'results/'
python llm_project/llm/test_llms.py --models all --shots zero one few --output results/

# Example 3: Run SmolLM2 with zero-shot on specific tasks (0 and 1)
python llm_project/llm/test_llms.py --models smollm2 --shots zero --tasks 0 1
```

NOTE: To use llama you must include a hugging face access token in a .env file. lamma_token=XXXXXXX

## Testing Task Decomposition

The script `test_decomposition.py` is used to generate the JSON output to be used with the selected LLM model. You can find it at `llm_project/llm/test_decomposition.py`.

To run the script:

```bash
python llm_project/llm/test_decomposition.py --task "<instruction>"
```

