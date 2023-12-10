#include <iostream>
#include <vector>
#include <omp.h>

namespace RedMF::Kernel {

template <typename T>
using kernelFuncType = std::function<T(std::vector<T>, std::vector<T>)>;

template <typename T>
std::vector<T> parallelizedMatrixMultiplication(std::vector<T> A, std::vector<T> B) {
    // Check if the input matrices are valid
    if (A.size() != B.size()) {
        throw std::invalid_argument("Input matrices must be of the same size");
    }

    // Get the size of the input matrices
    int n = A.size();

    // Create a new vector to store the resulting matrix C
    std::vector<T> C(n * n);

    // Parallelize the matrix multiplication using OpenMP
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            T sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[i * n + k] * B[k * n + j];
            }
            C[i * n + j] = sum;
        }
    }

    return C;
}

} // namespace RedMF::Kernel
