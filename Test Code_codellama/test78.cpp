#include <iostream>
#include <hip/hip_runtime.h>
#include <rocblas.h>
#include <rocsparse.h>

class MatrixOperations {
public:
    MatrixOperations() {
        // Initialize HIP backend
        rocalution_init_hip();
    }

    ~MatrixOperations() {
        // Release HIP resources
        rocalution_stop_hip();
    }

    void initializeMatrix(int m, int n) {
        // Allocate memory for the matrix on the HIP device
        hipMalloc((void**)&d_A, m * n * sizeof(float));

        // Initialize the matrix with random values
        hipMemset(d_A, 0, m * n * sizeof(float));
    }

    void addMatrices(float* A, float* B, float* C) {
        // Perform matrix addition using rocBLAS
        rocblas_status status = rocblas_saxpy(m, n, A, B, C);
        if (status != rocblas_status_success) {
            std::cerr << "rocBLAS error: " << status << std::endl;
            return;
        }

        // Sync the device
        rocalution_hip_sync();
    }

    void multiplyMatrices(float* A, float* B, float* C) {
        // Perform matrix multiplication using rocSPARSE
        rocsparse_status status = rocsparse_sparse_gemm(m, n, k, A, B, C);
        if (status != rocsparse_status_success) {
            std::cerr << "rocSPARSE error: " << status << std::endl;
            return;
        }

        // Sync the device
        rocalution_hip_sync();
    }

private:
    int m, n, k;
    float* d_A;
};
