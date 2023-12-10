python
from typing import List

def runScript(script: str) -> int:
    # Simulated function to execute the script and return the result
    # Replace this with actual script execution logic
    return 0  # Placeholder return value

def find_failing_script(scripts: List[str]) -> int:
    for i, script in enumerate(scripts):
        if runScript(script) != 0:
            return i
    return -1
