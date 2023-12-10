#include <amp.h>
#include <iostream>

void initializeMatrix(Concurrency::array<float, 2>& matrix, int rows, int cols) {
    // Initialize the matrix with random values
    Concurrency::array_view<float, 2> av(matrix);
    Concurrency::parallel_for_each(av.extent, [=](Concurrency::index<2> idx) restrict(amp) {
        av[idx] = static_cast<float>(rand() % 10);  // Initialize with random values between 0 and 9
    });
    av.synchronize();
}

void matrixMultiplication(const Concurrency::array<float, 2>& matrixA, const Concurrency::array<float, 2>& matrixB, Concurrency::array<float, 2>& result) {
    Concurrency::array_view<const float, 2> avA(matrixA);
    Concurrency::array_view<const float, 2> avB(matrixB);
    Concurrency::array_view<float, 2> avResult(result);

    Concurrency::parallel_for_each(result.extent, [=](Concurrency::index<2> idx) restrict(amp) {
        int row = idx[0];
        int col = idx[1];
        float sum = 0.0f;
        for (int i = 0; i < matrixA.extent[1]; i++) {
            sum += avA(row, i) * avB(i, col);
        }
        avResult[idx] = sum;
    });
    avResult.synchronize();
}

void printMatrix(const Concurrency::array<float, 2>& matrix, int rows, int cols) {
    Concurrency::array_view<const float, 2> av(matrix);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << av(i, j) << " ";
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
