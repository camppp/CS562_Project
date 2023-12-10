python
def checkWin(board, currentPiece, x, y):
    directions = [(0, 1), (1, 0), (1, 1), (1, -1)]  # right, down, diagonal right, diagonal left

    for dx, dy in directions:
        count = 1
        row, col = x, y

        # Check in both directions for each possible winning line
        for _ in range(2):
            row, col = x, y
            while 0 <= row + dx < len(board) and 0 <= col + dy < len(board[0]) and board[row + dx][col + dy] == currentPiece:
                count += 1
                if count >= 5:
                    return True
                row, col = row + dx, col + dy
            dx, dy = -dx, -dy  # reverse direction for the second iteration

    return False
