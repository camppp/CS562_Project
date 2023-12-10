#include <cstddef>

class MemoryPool {
public:
    MemoryPool(std::size_t size) : poolSize_(size), freeList_(nullptr) {}

    void* allocate(std::size_t size) {
        // Check if there is enough space in the pool for the allocation
        if (size > poolSize_) {
            return nullptr;
        }

        // Find a free block in the pool that is large enough for the allocation
        void* ptr = findFreeBlock(size);
        if (ptr == nullptr) {
            return nullptr;
        }

        // Mark the block as allocated
        markBlockAllocated(ptr, size);

        return ptr;
    }

    void deallocate(void* ptr) {
        // Find the block that contains the given pointer
        Block* block = findBlock(ptr);
        if (block == nullptr) {
            return;
        }

        // Mark the block as free
        markBlockFree(block);
    }

    std::size_t poolSize() const {
        return poolSize_;
    }

private:
    // The size of the memory pool
    std::size_t poolSize_;

    // The head of the free list
    Block* freeList_;

    // A linked list of free blocks
    struct Block {
        Block* next;
        std::size_t size;
    };

    // Find a free block in the pool that is large enough for the allocation
    void* findFreeBlock(std::size_t size) {
        Block* block = freeList_;
        while (block != nullptr) {
            if (block->size >= size) {
                return block;
            }
            block = block->next;
        }
        return nullptr;
    }

    // Mark the block as allocated
    void markBlockAllocated(void* ptr, std::size_t size) {
        Block* block = findBlock(ptr);
        if (block == nullptr) {
            return;
        }
        block->size = size;
        block->next = nullptr;
    }

    // Mark the block as free
    void markBlockFree(Block* block) {
        block->size = 0;
        block->next = freeList_;
        freeList_ = block;
    }

    // Find the block that contains the given pointer
    Block* findBlock(void* ptr) {
        Block* block = freeList_;
        while (block != nullptr) {
            if (ptr >= block && ptr < block + block->size) {
                return block;
            }
            block = block->next;
        }
        return nullptr;
    }
};
