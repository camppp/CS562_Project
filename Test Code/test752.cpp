python
from typing import List

def bubbleSortAndCountSwaps(arr: List[int]) -> int:
    n = len(arr)
    numberOfSwaps = 0
    for i in range(n):
        for j in range(n - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                numberOfSwaps += 1
        if numberOfSwaps == 0:
            break
    return numberOfSwaps
