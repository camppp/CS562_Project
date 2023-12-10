python
from typing import List

def maxPathSum(grid: List[List[int]]) -> int:
    rows, cols = len(grid), len(grid[0])
    
    # Initialize the first row
    for j in range(1, cols):
        grid[0][j] += grid[0][j-1]
    
    # Initialize the first column
    for i in range(1, rows):
        grid[i][0] += grid[i-1][0]
    
    # Calculate the maximum sum for each cell
    for i in range(1, rows):
        for j in range(1, cols):
            grid[i][j] += max(grid[i-1][j], grid[i][j-1])
    
    return grid[rows-1][cols-1]
