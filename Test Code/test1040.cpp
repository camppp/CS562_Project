#include <iostream>
#include <cstring>

class MemoryPool {
private:
    char* memory;
    std::size_t totalPoolSize;
    bool* allocationMap;

public:
    MemoryPool(std::size_t size) : totalPoolSize(size) {
        memory = new char[size];
        allocationMap = new bool[size];
        std::memset(allocationMap, false, size);
    }

    void* allocate(std::size_t size) {
        for (std::size_t i = 0; i < totalPoolSize; ++i) {
            if (!allocationMap[i]) {
                bool canAllocate = true;
                for (std::size_t j = i; j < i + size; ++j) {
                    if (j >= totalPoolSize || allocationMap[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (std::size_t j = i; j < i + size; ++j) {
                        allocationMap[j] = true;
                    }
                    return &memory[i];
                }
            }
        }
        return nullptr; // No suitable block found for allocation
    }

    void deallocate(void* ptr) {
        char* charPtr = static_cast<char*>(ptr);
        std::size_t index = charPtr - memory;
        if (index < totalPoolSize) {
            allocationMap[index] = false;
        }
    }

    std::size_t poolSize() const { return totalPoolSize; }

    ~MemoryPool() {
        delete[] memory;
        delete[] allocationMap;
    }
};

int main() {
    MemoryPool pool(100);
    std::cout << "Pool size: " << pool.poolSize() << std::endl;

    void* block1 = pool.allocate(20);
    void* block2 = pool.allocate(30);

    std::cout << "Allocated block 1 at address: " << block1 << std::endl;
    std::cout << "Allocated block 2 at address: " << block2 << std::endl;

    pool.deallocate(block1);
    pool.deallocate(block2);

    return 0;
}
