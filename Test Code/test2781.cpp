c
#include <iostream>
#include <vector>
#include <immintrin.h>

int sumMatrixUsingSIMD(int** matrix, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main() {
    int rows = 3;
    int cols = 3;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1;
        }
    }
    int sum = sumMatrixUsingSIMD(matrix, rows, cols);
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}
