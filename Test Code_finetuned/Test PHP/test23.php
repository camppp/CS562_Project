def formatReaction(voter, userRating=None, candidate, candidateRating=None):
    voter_str = f"{voter}"
    if userRating is not None:
        voter_str += f" ({userRating})"

    candidate_str = f"{candidate}"
    if candidateRating is not None:
        candidate_str += f" ({candidateRating})"

    return f"{voter_str} reacted to a message from {candidate_str}"