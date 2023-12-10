#include <spla-cpp/SplaUtils.hpp>
#include <iostream>

int main() {
    // Initialize the SPLA context
    spla::Context ctx;

    // Define the dimensions of the matrices
    const int rowsA = 3;
    const int colsA = 3;
    const int rowsB = 3;
    const int colsB = 3;

    // Initialize the matrices
    spla::Matrix matrixA(ctx, rowsA, colsA);
    spla::Matrix matrixB(ctx, rowsB, colsB);
    spla::Matrix resultMatrix(ctx, rowsA, colsB);

    // Populate the matrices with values (omitted for brevity)

    // Perform matrix-matrix multiplication
    spla::gemm(1.0, matrixA, matrixB, 0.0, resultMatrix);

    // Print the result matrix
    std::cout << "Result Matrix:" << std::endl;
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            std::cout << resultMatrix(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
