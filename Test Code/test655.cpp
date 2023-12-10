#include <cstddef>
#include <cstdint>
#include <cassert>

template <std::size_t SIZE>
class StackAllocator {
public:
    StackAllocator() : buffer_(nullptr) {}

    ~StackAllocator() {
        if (buffer_) {
            delete[] buffer_;
        }
    }

    void* allocate(std::size_t size) {
        assert(size <= SIZE);
        if (buffer_ == nullptr) {
            buffer_ = new uint8_t[SIZE];
        }
        void* ptr = buffer_ + (SIZE - size);
        return ptr;
    }

    void deallocate(void* ptr) {
        assert(ptr >= buffer_ && ptr < buffer_ + SIZE);
        // Do nothing, since the memory is freed when the stack allocator is destroyed
    }

private:
    uint8_t* buffer_;
};

int main() {
    StackAllocator<1024> allocator;

    // Allocate 100 bytes
    void* ptr1 = allocator.allocate(100);
    assert(ptr1 != nullptr);

    // Allocate 200 bytes
    void* ptr2 = allocator.allocate(200);
    assert(ptr2 != nullptr);

    // Deallocate the first allocation
    allocator.deallocate(ptr1);

    // Allocate 300 bytes
    void* ptr3 = allocator.allocate(300);
    assert(ptr3 != nullptr);

    // Deallocate the second allocation
    allocator.deallocate(ptr2);

    // Deallocate the third allocation
    allocator.deallocate(ptr3);

    return 0;
}
