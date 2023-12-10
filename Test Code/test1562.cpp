#include <cuda/api/array.hpp>
#include <cuda/api/error.hpp>
#include <cuda_runtime.h>

namespace cuda {
    __global__ void addArrays(const float* a, const float* b, float* result, size_t size) {
        size_t index = blockIdx.x * blockDim.x + threadIdx.x;
        if (index < size) {
            result[index] = a[index] + b[index];
        }
    }

    void performElementWiseAddition(const float* hostA, const float* hostB, float* hostResult, size_t size) {
        float *deviceA, *deviceB, *deviceResult;
        cudaMalloc((void**)&deviceA, size * sizeof(float));
        cudaMalloc((void**)&deviceB, size * sizeof(float));
        cudaMalloc((void**)&deviceResult, size * sizeof(float));

        cudaMemcpy(deviceA, hostA, size * sizeof(float), cudaMemcpyHostToDevice);
        cudaMemcpy(deviceB, hostB, size * sizeof(float), cudaMemcpyHostToDevice);

        addArrays<<<(size + 255) / 256, 256>>>(deviceA, deviceB, deviceResult, size);

        cudaMemcpy(hostResult, deviceResult, size * sizeof(float), cudaMemcpyDeviceToHost);

        cudaFree(deviceA);
        cudaFree(deviceB);
        cudaFree(deviceResult);
    }
}
