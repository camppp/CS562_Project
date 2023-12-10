#include <iostream>
#include <cassert>
#include <cstdint>
#include <cstring>

namespace Debug
{
    template<size_t SIZE>
    class StackAllocator
    {
    public:
        StackAllocator() : top_(0) {
            static_assert(SIZE > 0, "SIZE must be greater than 0");
            static_assert((SIZE & (SIZE - 1)) == 0, "SIZE must be a power of 2 for alignment");
            static_assert(SIZE <= UINT32_MAX, "SIZE must be within the range of uint32_t");
            static_assert(alignof(std::max_align_t) <= 4, "Alignment must be <= 4 for this example");
        }

        void* allocate(size_t bytes) {
            assert(top_ + bytes <= SIZE && "Out of memory");
            void* ptr = &buffer_[top_];
            top_ += bytes;
            return ptr;
        }

        void deallocate(void* ptr, size_t bytes) {
            assert(bytes <= top_ && "Invalid deallocation size");
            assert(ptr == &buffer_[top_ - bytes] && "Invalid deallocation pointer");
            top_ -= bytes;
        }

    private:
        uint8_t buffer_[SIZE];
        size_t top_;
    };
}

int main() {
    Debug::StackAllocator<1024> allocator;

    // Allocate memory
    int* intPtr = static_cast<int*>(allocator.allocate(sizeof(int)));
    *intPtr = 42;

    // Deallocate memory
    allocator.deallocate(intPtr, sizeof(int));

    return 0;
}
