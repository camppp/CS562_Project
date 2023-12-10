bool canPlaceQueen(int grid[][n], int row, int col, int n) {
    // Check if the new queen is already on the board
    if (grid[row][col] == 1) {
        return false;
    }

    // Check if the new queen is attacking any other queen
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && abs(i - row) == abs(j - col)) {
                return false;
            }
        }
    }

    return true;
}
