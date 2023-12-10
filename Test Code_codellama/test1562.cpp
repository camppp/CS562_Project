#include <cuda/api/array.hpp>
#include <cuda/api/error.hpp>
#include <cuda_runtime.h>

namespace cuda {

__global__ void elementwise_add(const float* a, const float* b, float* c, int n) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < n) {
        c[i] = a[i] + b[i];
    }
}

void elementwise_add(const float* a, const float* b, float* c, int n) {
    int block_size = 256;
    int num_blocks = (n + block_size - 1) / block_size;

    elementwise_add<<<num_blocks, block_size>>>(a, b, c, n);

    cudaError_t err = cudaGetLastError();
    if (err != cudaSuccess) {
        fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
        exit(1);
    }

    cudaFree(a);
    cudaFree(b);
    cudaFree(c);
}

} // namespace cuda
