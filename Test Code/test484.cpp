python
from typing import List

def processOperations(initialGrid: List[List[str]], operations: List[str]) -> List[List[str]]:
    grid = [row[:] for row in initialGrid]  # Create a copy of the initial grid

    for operation in operations:
        if "removed" in operation:
            letter, pos = operation.split(" removed at position ")[0], operation.split(" removed at position ")[1]
            i, j = map(int, pos.strip("()").split(", "))
            grid[i-1][j-1] = ''  # Remove the letter at the specified position
        elif "added" in operation:
            letter, pos = operation.split(" added at position ")[0], operation.split(" added at position ")[1]
            i, j, k = map(int, pos.strip("()").split(", "))
            grid[i-1][j-1] = letter  # Add the letter at the specified position

    return grid
