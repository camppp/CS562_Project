#include <iostream>
#include <map>

class MemoryManager {
public:
    static std::map<void*, size_t> allocations;

    static void* allocate(size_t size) {
        void* ptr = ::operator new(size);
        allocations[ptr] = size;
        return ptr;
    }

    static void deallocate(void* ptr) {
        auto it = allocations.find(ptr);
        if (it != allocations.end()) {
            ::operator delete(ptr);
            allocations.erase(it);
        }
    }

    static void checkForLeaks() {
        if (!allocations.empty()) {
            std::cerr << "Memory leaks detected!" << std::endl;
            for (const auto& pair : allocations) {
                std::cerr << "Leaked memory at address: " << pair.first << ", size: " << pair.second << " bytes" << std::endl;
            }
        } else {
            std::cout << "No memory leaks detected." << std::endl;
        }
    }

    static void reportMemoryUsage() {
        size_t totalAllocated = 0;
        for (const auto& pair : allocations) {
            totalAllocated += pair.second;
        }
        std::cout << "Total memory allocated: " << totalAllocated << " bytes" << std::endl;
        std::cout << "Total memory deallocated: " << totalDeallocated << " bytes" << std::endl;
    }
};

std::map<void*, size_t> MemoryManager::allocations;

void* operator new(size_t size) {
    return MemoryManager::allocate(size);
}

void operator delete(void* ptr) noexcept {
    MemoryManager::deallocate(ptr);
}

size_t totalDeallocated = 0;

int main() {
    int* ptr1 = new int(10);
    int* ptr2 = new int(20);

    MemoryManager::reportMemoryUsage();

    delete ptr1;

    MemoryManager::reportMemoryUsage();

    MemoryManager::checkForLeaks();

    return 0;
}
