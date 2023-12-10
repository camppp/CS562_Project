python
def knightMoves(board, startRow, startCol, moves):
    rows, cols = len(board), len(board[0])
    directions = [(2, 1), (1, 2), (-1, 2), (-2, 1), (-2, -1), (-1, -2), (1, -2), (2, -1)]

    def is_valid(row, col):
        return 0 <= row < rows and 0 <= col < cols

    dp = [[0] * cols for _ in range(rows)]
    dp[startRow][startCol] = 1

    for _ in range(moves):
        new_dp = [[0] * cols for _ in range(rows)]
        for r in range(rows):
            for c in range(cols):
                if dp[r][c] > 0:
                    for dr, dc in directions:
                        nr, nc = r + dr, c + dc
                        if is_valid(nr, nc):
                            new_dp[nr][nc] += dp[r][c]
        dp = new_dp

    return sum(sum(row) for row in dp)
