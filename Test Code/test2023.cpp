#ifndef ROCSHMEM_LIBRARY_SRC_DEVICE_MUTEX_HPP
#define ROCSHMEM_LIBRARY_SRC_DEVICE_MUTEX_HPP

#include <hip/hip_runtime.h>

class DeviceMutex {
public:
    __device__ DeviceMutex() : locked(false) {}

    __device__ void lock() {
        while (atomicCAS(&locked, 0, 1) != 0) {
            // Spin until the mutex is available
        }
    }

    __device__ void unlock() {
        atomicExch(&locked, 0);
    }

private:
    int locked;
};

#endif
