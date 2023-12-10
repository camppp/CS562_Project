#include <iostream>
#include <cstdlib>

// Base Allocator class with pure virtual functions
class Allocator {
public:
    virtual void* allocate(size_t size) = 0;
    virtual void deallocate(void* ptr) = 0;
};

// Custom allocator inheriting from the base Allocator class
class MySystemAllocator : public Allocator {
public:
    // Override the allocate function to use aligned version of malloc
    void* allocate(size_t size) override {
        return aligned_malloc(size, 16);  // Using aligned_malloc for aligned memory allocation
    }

    // Override the deallocate function to free the allocated memory
    void deallocate(void* ptr) override {
        aligned_free(ptr);  // Freeing the memory allocated using aligned_malloc
    }

private:
    // Custom aligned memory allocation function
    void* aligned_malloc(size_t size, size_t alignment) {
        void* ptr = nullptr;
        if (posix_memalign(&ptr, alignment, size) != 0) {
            throw std::bad_alloc();  // Throw bad_alloc exception if memory allocation fails
        }
        return ptr;
    }

    // Custom aligned memory deallocation function
    void aligned_free(void* ptr) {
        free(ptr);  // Free the memory allocated using aligned_malloc
    }
};

int main() {
    MySystemAllocator customAllocator;
    void* memory = customAllocator.allocate(100);  // Allocate 100 bytes of memory
    std::cout << "Memory allocated using custom allocator" << std::endl;
    customAllocator.deallocate(memory);  // Deallocate the memory
    std::cout << "Memory deallocated using custom allocator" << std::endl;
    return 0;
}
