#include <iostream>

class MemoryAllocator {
private:
    size_t poolSize;
    uint8_t* memoryPool;

public:
    MemoryAllocator(size_t poolSize) : poolSize(poolSize) {
        memoryPool = new uint8_t[poolSize];
    }

    void* allocate(size_t blockSize) {
        for (size_t i = 0; i < poolSize; ++i) {
            if (memoryPool[i] == 0) {
                size_t blockSizeCount = 0;
                while (i + blockSizeCount < poolSize && memoryPool[i + blockSizeCount] == 0 && blockSizeCount < blockSize) {
                    blockSizeCount++;
                }
                if (blockSizeCount == blockSize) {
                    for (size_t j = i; j < i + blockSize; ++j) {
                        memoryPool[j] = 1;
                    }
                    return &memoryPool[i];
                }
                i += blockSizeCount;
            }
        }
        return nullptr;
    }

    void free(void* ptr) {
        uint8_t* blockPtr = static_cast<uint8_t*>(ptr);
        size_t index = blockPtr - memoryPool;
        for (size_t i = index; i < poolSize && memoryPool[i] == 1; ++i) {
            memoryPool[i] = 0;
        }
    }

    ~MemoryAllocator() {
        delete[] memoryPool;
    }
};

int main() {
    MemoryAllocator allocator(1024);
    void* block1 = allocator.allocate(100);
    if (block1) {
        std::cout << "Block 1 allocated successfully" << std::endl;
    } else {
        std::cout << "Failed to allocate Block 1" << std::endl;
    }

    void* block2 = allocator.allocate(200);
    if (block2) {
        std::cout << "Block 2 allocated successfully" << std::endl;
    } else {
        std::cout << "Failed to allocate Block 2" << std::endl;
    }

    allocator.free(block1);
    std::cout << "Block 1 freed" << std::endl;

    void* block3 = allocator.allocate(150);
    if (block3) {
        std::cout << "Block 3 allocated successfully" << std::endl;
    } else {
        std::cout << "Failed to allocate Block 3" << std::endl;
    }

    return 0;
}
