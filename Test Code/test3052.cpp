python
from typing import List

def minSumPath(matrix: List[List[int]]) -> int:
    n = len(matrix)

    # Update the matrix to store the cumulative sum from each cell to the bottom-right cell
    for y in range(n - 2, -1, -1):
        matrix[y][n - 1] += matrix[y + 1][n - 1]
        matrix[n - 1][y] += matrix[n - 1][y + 1]

    for y in range(n - 2, -1, -1):
        for x in range(n - 2, -1, -1):
            matrix[y][x] += min(matrix[y + 1][x], matrix[y][x + 1])

    return matrix[0][0]
