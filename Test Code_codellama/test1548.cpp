class MemoryManager {
public:
    MemoryManager() {
        // Initialize the memory allocation and deallocation counters
        allocated_memory = 0;
        deallocated_memory = 0;
    }

    ~MemoryManager() {
        // Report the total memory allocated and deallocated
        std::cout << "Total memory allocated: " << allocated_memory << std::endl;
        std::cout << "Total memory deallocated: " << deallocated_memory << std::endl;

        // Check for memory leaks
        if (allocated_memory != deallocated_memory) {
            std::cout << "Memory leak detected!" << std::endl;
        }
    }

    void* operator new(size_t size) {
        // Increment the memory allocation counter
        allocated_memory += size;

        // Allocate memory using the default operator new
        void* ptr = ::operator new(size);

        // Return the allocated memory
        return ptr;
    }

    void operator delete(void* ptr) {
        // Decrement the memory deallocation counter
        deallocated_memory += size;

        // Deallocate memory using the default operator delete
        ::operator delete(ptr);
    }

private:
    size_t allocated_memory;
    size_t deallocated_memory;
};
