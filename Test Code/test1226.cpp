#include <stdlib.h>

int **array;
int numRows, numCols;

void create(int rows, int cols) {
    numRows = rows;
    numCols = cols;
    array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
    }
}

int get(int row, int col) {
    if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
        return -1; // Invalid index
    }
    return array[row][col];
}

void set(int row, int col, int value) {
    if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
        array[row][col] = value;
    }
}
