#include <cstddef>
#include <cstdlib>
#include <cassert>

class SlabAllocator {
public:
    SlabAllocator(size_t slabSize, size_t numSlabs) : slabSize_(slabSize), numSlabs_(numSlabs) {
        slabs_ = new char[slabSize_ * numSlabs_];
    }

    ~SlabAllocator() {
        delete[] slabs_;
    }

    void* allocate() {
        if (freeList_.empty()) {
            // Allocate a new slab if the free list is empty
            slabs_.push_back(new char[slabSize_]);
        }

        // Allocate a block from the free list
        void* ptr = freeList_.front();
        freeList_.pop_front();
        return ptr;
    }

    void deallocate(void* ptr) {
        // Add the block to the free list
        freeList_.push_back(ptr);
    }

private:
    size_t slabSize_;
    size_t numSlabs_;
    std::list<char*> slabs_;
    std::list<void*> freeList_;
};
