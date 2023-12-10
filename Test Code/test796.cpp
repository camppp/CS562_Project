#include <omp.h>
#include <vector>
#include <functional>

namespace RedMF::Kernel {
    template <typename T>
    using kernelFuncType = std::function<std::vector<T>(std::vector<T>, std::vector<T>)>;

    template <typename T>
    std::vector<T> matrixMultiplication(const std::vector<T>& A, const std::vector<T>& B, int N) {
        std::vector<T> C(N * N, 0);

        #pragma omp parallel for
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    C[i * N + j] += A[i * N + k] * B[k * N + j];
                }
            }
        }

        return C;
    }

    template <typename T>
    kernelFuncType<T> parallelMatrixMultiplication = [](std::vector<T> A, std::vector<T> B) {
        int N = static_cast<int>(std::sqrt(A.size())); // Assuming A and B are square matrices
        return matrixMultiplication(A, B, N);
    };
}
