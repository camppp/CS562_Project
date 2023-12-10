#include <cstdlib>
#include <cstddef>

class MySystemAllocator : public Allocator {
public:
    MySystemAllocator() {}
    ~MySystemAllocator() {}

    void* allocate(size_t size, size_t alignment) override {
        return aligned_malloc(size, alignment);
    }

    void deallocate(void* ptr) override {
        aligned_free(ptr);
    }
};
