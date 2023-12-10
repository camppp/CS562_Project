#include <iostream>

class MemoryAllocator {
private:
    size_t poolSize;
    uint8_t* memoryPool;
    size_t freeListSize;
    uint8_t* freeList;

public:
    MemoryAllocator(size_t poolSize) : poolSize(poolSize) {
        memoryPool = new uint8_t[poolSize];
        freeListSize = 0;
        freeList = nullptr;
    }

    void* allocate(size_t blockSize) {
        if (blockSize > poolSize) {
            return nullptr;
        }

        if (freeListSize >= blockSize) {
            void* ptr = freeList;
            freeList += blockSize;
            freeListSize -= blockSize;
            return ptr;
        }

        void* ptr = memoryPool;
        memoryPool += blockSize;
        return ptr;
    }

    void free(void* ptr) {
        if (ptr < memoryPool || ptr >= memoryPool + poolSize) {
            return;
        }

        size_t blockSize = ptr - memoryPool;
        if (freeListSize + blockSize > poolSize) {
            return;
        }

        freeList += blockSize;
        freeListSize += blockSize;
    }

    ~MemoryAllocator() {
        delete[] memoryPool;
    }
};
