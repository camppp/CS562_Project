#include <amp.h>
#include <iostream>

void initializeMatrix(Concurrency::array<float, 2>& matrix, int rows, int cols) {
    // Initialize the matrix with random values
    Concurrency::parallel_for_each(matrix.extent, [&](Concurrency::index<2> idx) {
        matrix[idx] = (float)rand() / RAND_MAX;
    });
}

void matrixMultiplication(const Concurrency::array<float, 2>& matrixA, const Concurrency::array<float, 2>& matrixB, Concurrency::array<float, 2>& result) {
    // Perform matrix multiplication using C++ AMP
    Concurrency::parallel_for_each(result.extent, [&](Concurrency::index<2> idx) {
        float sum = 0;
        for (int i = 0; i < matrixA.extent[0]; i++) {
            for (int j = 0; j < matrixB.extent[1]; j++) {
                sum += matrixA[i][j] * matrixB[j][i];
            }
        }
        result[idx] = sum;
    });
}

void printMatrix(const Concurrency::array<float, 2>& matrix, int rows, int cols) {
    // Print the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Define matrix dimensions
    int rowsA = 3;
    int colsA = 3;
    int rowsB = 3;
    int colsB = 3;

    // Create input matrices and result matrix using Concurrency::array
    Concurrency::array<float, 2> matrixA(rowsA, colsA);
    Concurrency::array<float, 2> matrixB(rowsB, colsB);
    Concurrency::array<float, 2> result(rowsA, colsB);

    // Initialize input matrices
    initializeMatrix(matrixA, rowsA, colsA);
    initializeMatrix(matrixB, rowsB, colsB);

    // Perform matrix multiplication
    matrixMultiplication(matrixA, matrixB, result);

    // Print input matrices and the resulting matrix
    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA, rowsA, colsA);
    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixB, rowsB, colsB);
    std::cout << "Result:" << std::endl;
    printMatrix(result, rowsA, colsB);

    return 0;
}
