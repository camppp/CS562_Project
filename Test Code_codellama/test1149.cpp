def knightMoves(board, startRow, startCol, moves):
    # Initialize the count of possible positions to 0
    count = 0

    # Loop through the possible moves
    for row in range(startRow - 2, startRow + 3):
        for col in range(startCol - 2, startCol + 3):
            # Check if the current position is on the board and within the allowed moves
            if row >= 0 and row < len(board) and col >= 0 and col < len(board[0]) and abs(row - startRow) + abs(col - startCol) <= moves:
                # Increment the count of possible positions
                count += 1

    # Return the count of possible positions
    return count
