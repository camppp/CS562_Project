#include <hip/hip_runtime.h>
#include <hipblas.h>
#include <hipsparse.h>
#include <iostream>

class MatrixOperations {
private:
    hipblasHandle_t handle;
    hipsparseHandle_t sparseHandle;

public:
    MatrixOperations() {
        if (rocalution_init_hip()!= HIP_SUCCESS) {
            std::cerr << "Failed to initialize HIP backend." << std::endl;
            exit(1);
        }

        hipblasCreate(&handle);
        hipsparseCreate(&sparseHandle);
    }

    ~MatrixOperations() {
        hipblasDestroy(handle);
        hipsparseDestroy(sparseHandle);
        rocalution_stop_hip();
    }

    void initializeMatrix(int rows, int cols, float* matrix) {
        hipError_t err = hipMemcpy(matrix, matrix, rows * cols * sizeof(float), hipMemcpyHostToDevice);
        if (err!= HIP_SUCCESS) {
            std::cerr << "Failed to initialize matrix on HIP device." << std::endl;
            exit(1);
        }
    }

    void addMatrices(int rows, int cols, float* matrix1, float* matrix2, float* result) {
        hipblasSaxpy(handle, rows * cols, &alpha, matrix1, 1, result, 1);
        hipblasSaxpy(handle, rows * cols, &alpha, matrix2, 1, result, 1);
        rocalution_hip_sync();
    }

    void multiplyMatrices(int rows, int cols, float* matrix1, float* matrix2, float* result) {
        hipsparseSgemm(sparseHandle, HIPSPARSE_OP_N, HIPSPARSE_OP_N, rows, cols, rows, &alpha, matrix1, rows, matrix2, rows, &beta, result, rows);
        rocalution_hip_sync();
    }
};