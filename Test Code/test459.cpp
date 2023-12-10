python
from typing import List

def caseCombinations(S: str) -> List[str]:
    def backtrack(index, current):
        if index == len(S):
            result.append(current)
            return
        if S[index].isalpha():
            backtrack(index + 1, current + S[index].lower())
            backtrack(index + 1, current + S[index].upper())
        else:
            backtrack(index + 1, current + S[index])

    result = []
    backtrack(0, "")
    return result
