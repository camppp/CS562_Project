python
from typing import List

def calculateTotalScore(scores: List[int]) -> List[int]:
    total_scores = []
    for i in range(len(scores)):
        player_scores = scores[i]
        player_total = sum(sorted(player_scores, reverse=True)[:3]) if len(player_scores) >= 3 else sum(player_scores)
        total_scores.append(player_total)
    return total_scores
