bool canPlaceQueen(int grid[][n], int row, int col, int n) {
    // Check if there is any queen in the same column
    for (int i = row - 1; i >= 0; i--) {
        if (grid[i][col] == 1) {
            return false;
        }
    }

    // Check if there is any queen in the upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (grid[i][j] == 1) {
            return false;
        }
    }

    // Check if there is any queen in the upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (grid[i][j] == 1) {
            return false;
        }
    }

    // If no queen is found in the same column or diagonals, the new queen can be placed
    return true;
}
