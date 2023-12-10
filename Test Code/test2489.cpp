python
from typing import List, Tuple
import re

def maxWeightWithoutViolation(constraints: List[Tuple[int, str]]) -> int:
    max_weight = 0
    for weight, condition in constraints:
        if all(eval(re.sub(r'x(\d+)', r'\1', condition))):
            max_weight = max(max_weight, weight)
    return max_weight

# Test the function with the provided example
constraints = [
    (1, "abs(x14 - x322) > 11"),
    (1, "abs(x14 - x323) > 56"),
    (10, "abs(x14 - x324) > 151"),
    (10, "abs(x14 - x557) > 265")
]
print(maxWeightWithoutViolation(constraints))  # Output: 10
