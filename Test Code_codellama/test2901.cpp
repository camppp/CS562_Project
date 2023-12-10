def maxPathSum(grid: List[List[int]]) -> int:
    # Initialize the maximum sum to 0
    max_sum = 0

    # Loop through each row of the grid
    for i in range(len(grid)):
        # Loop through each column of the grid
        for j in range(len(grid[i])):
            # If we are at the top-left cell, set the maximum sum to the value of that cell
            if i == 0 and j == 0:
                max_sum = grid[i][j]
            # If we are at the bottom-right cell, set the maximum sum to the value of that cell
            elif i == len(grid) - 1 and j == len(grid[i]) - 1:
                max_sum = grid[i][j]
            # If we are in any other cell, set the maximum sum to the maximum of the sum of the current cell and the sum of the previous cell
            else:
                max_sum = max(max_sum, grid[i][j] + maxPathSum(grid[i - 1][j - 1]))

    return max_sum
