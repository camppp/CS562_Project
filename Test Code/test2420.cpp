python
from typing import List

def maximize_starting_index(scores: List[int]) -> int:
    n = len(scores)
    if n < 2:
        return 0

    max_score = float('-inf')
    start_index = 0

    for i in range(n - 2, -1, -1):
        score1 = scores[i]
        score2 = scores[i + 1]
        total_score = score1 + score2
        j = i + 2
        while j < n:
            score1, score2 = score2, total_score
            total_score = score1 + score2
            j += 1
        if total_score > max_score:
            max_score = total_score
            start_index = i

    return start_index
