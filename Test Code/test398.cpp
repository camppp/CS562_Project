#include <iostream>
#include <vector>
#include <cstdlib>

typedef std::vector<std::vector<int>> row;

// Function to initialize a matrix with random values
std::vector<row> initializeMatrix(const std::vector<row>& matrix) {
    std::vector<row> result(matrix.size(), row(matrix[0].size()));
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[0].size(); ++j) {
            result[i][j] = rand() % 10;  // Initialize with random values between 0 and 9
        }
    }
    return result;
}

// Function to perform matrix multiplication
std::vector<row> matrixMultiplication(const std::vector<row>& A, const std::vector<row>& B) {
    size_t m = A.size();
    size_t n = A[0].size();
    size_t p = B[0].size();

    if (n != B.size()) {
        throw "Matrix dimensions are not suitable for multiplication";
    }

    std::vector<row> C(m, row(p, 0));

    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < p; ++j) {
            for (size_t k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

int main() {
    std::vector<row> A(10, row(5));
    std::vector<row> B(5, row(5));
    std::vector<row> C;

    A = initializeMatrix(A);
    B = initializeMatrix(B);

    try {
        C = matrixMultiplication(A, B);
        // Print the result matrix C
        for (size_t i = 0; i < C.size(); ++i) {
            for (size_t j = 0; j < C[0].size(); ++j) {
                std::cout << C[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } catch (const char* msg) {
        std::cerr << "Error: " << msg << std::endl;
    }

    return 0;
}
