#include <iostream>
#include <vector>

class SlabAllocator {
private:
    size_t slabSize;
    size_t numSlabs;
    std::vector<void*> memoryBlocks;
    std::vector<void*> freeBlocks;

public:
    SlabAllocator(size_t slabSize, size_t numSlabs) : slabSize(slabSize), numSlabs(numSlabs) {
        for (size_t i = 0; i < numSlabs; ++i) {
            void* slab = malloc(slabSize);
            memoryBlocks.push_back(slab);
            freeBlocks.push_back(slab);
        }
    }

    void* allocate() {
        if (freeBlocks.empty()) {
            std::cerr << "Out of memory" << std::endl;
            return nullptr;
        }
        void* allocatedBlock = freeBlocks.back();
        freeBlocks.pop_back();
        return allocatedBlock;
    }

    void deallocate(void* ptr) {
        freeBlocks.push_back(ptr);
    }

    ~SlabAllocator() {
        for (void* block : memoryBlocks) {
            free(block);
        }
    }
};

int main() {
    SlabAllocator smallAllocator(64, 10);

    void* block1 = smallAllocator.allocate();
    void* block2 = smallAllocator.allocate();

    smallAllocator.deallocate(block1);
    smallAllocator.deallocate(block2);

    return 0;
}
