void diagonalSwap(int matrix[][n], int n) {
    // Loop through the rows and columns of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // If the current element is on the main diagonal, swap it with the element on the secondary diagonal
            if (i == j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = temp;
            }
        }
    }
}
