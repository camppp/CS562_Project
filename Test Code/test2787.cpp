python
from typing import List

def findHIndex(citations: List[int]) -> int:
    citations.sort(reverse=True)  # Sort the citations in descending order
    hindex = 0
    for i in range(len(citations)):
        if citations[i] >= i + 1:  # Check if the current citation count is greater than or equal to the index
            hindex = i + 1  # Update the h-index
        else:
            break  # Stop the loop as the condition is no longer met
    return hindex
