python
def calculateTotalScore(scores):
    if len(scores) < 2:
        return sum(scores)
    total_score = sum(scores[:2])
    prev_prev_score = scores[0]
    prev_score = scores[1]
    for i in range(2, len(scores)):
        current_score = prev_prev_score + prev_score
        total_score += current_score
        prev_prev_score, prev_score = prev_score, current_score
    return total_score
