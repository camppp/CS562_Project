python
from typing import List, Dict, Union

def calculate_scores(scores: List[int]) -> Dict[str, Union[float, int]]:
    result = {}
    result['average_score'] = sum(scores) / len(scores)
    result['highest_score'] = max(scores)
    result['lowest_score'] = min(scores)
    return result
