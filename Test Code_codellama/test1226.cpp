void create(int rows, int cols) {
    // Allocate memory for the 2D array
    int** array = new int*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }

    // Initialize the 2D array with zeros
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = 0;
        }
    }
}

int get(int row, int col) {
    // Check if the row and column are within the bounds of the 2D array
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        return -1;
    }

    // Return the value at the specified position in the 2D array
    return array[row][col];
}

void set(int row, int col, int value) {
    // Check if the row and column are within the bounds of the 2D array
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        return;
    }

    // Update the value at the specified position in the 2D array
    array[row][col] = value;
}
