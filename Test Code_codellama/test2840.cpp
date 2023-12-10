#include <iostream>
#include <chrono>
#include <vector>
#include <memory>

// Custom allocator classes
namespace DS {
    class AllocatorSimple {
    public:
        void* allocate(size_t size) {
            return malloc(size);
        }

        void deallocate(void* ptr) {
            free(ptr);
        }
    };

    class AllocatorDefault {
    public:
        void* allocate(size_t size) {
            return std::allocator<void>::allocate(size);
        }

        void deallocate(void* ptr) {
            std::allocator<void>::deallocate(ptr);
        }
    };
}

// Test function to compare the performance of the custom allocators with std::allocator
void testAllocators() {
    // Object type to allocate
    using Object = int;

    // Number of objects to allocate
    constexpr size_t numObjects = 1000000;

    // Allocate objects using custom allocators
    DS::AllocatorSimple simpleAllocator;
    DS::AllocatorDefault defaultAllocator;
    std::vector<Object, DS::AllocatorSimple> simpleObjects(numObjects, simpleAllocator);
    std::vector<Object, DS::AllocatorDefault> defaultObjects(numObjects, defaultAllocator);

    // Measure time taken for allocation and deallocation using each allocator
    auto simpleAllocStart = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < numObjects; i++) {
        simpleObjects.push_back(Object());
    }
    auto simpleAllocEnd = std::chrono::high_resolution_clock::now();
    auto simpleAllocTime = std::chrono::duration_cast<std::chrono::milliseconds>(simpleAllocEnd - simpleAllocStart).count();

    auto defaultAllocStart = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < numObjects; i++) {
        defaultObjects.push_back(Object());
    }
    auto defaultAllocEnd = std::chrono::high_resolution_clock::now();
    auto defaultAllocTime = std::chrono::duration_cast<std::chrono::milliseconds>(defaultAllocEnd - defaultAllocStart).count();

    // Measure time taken for deallocation using each allocator
    auto simpleDeallocStart = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < numObjects; i++) {
        simpleObjects.pop_back();
    }
    auto simpleDeallocEnd = std::chrono::high_resolution_clock::now();
    auto simpleDeallocTime = std::chrono::duration_cast<std::chrono::milliseconds>(simpleDeallocEnd - simpleDeallocStart).count();

    auto defaultDeallocStart = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < numObjects; i++) {
        defaultObjects.pop_back();
    }
    auto defaultDeallocEnd = std::chrono::high_resolution_clock::now();
    auto defaultDeallocTime = std::chrono::duration_cast<std::chrono::milliseconds>(defaultDeallocEnd - defaultDeallocStart).count();

    // Analyze and compare the performance of the custom allocators with std::allocator
    std::cout << "Custom allocator (simple): " << simpleAllocTime << "ms" << std::endl;
    std::cout << "Custom allocator (default): " << defaultAllocTime << "ms" << std::endl;
    std::cout << "std::allocator: " << std::allocator<Object>::allocate(numObjects) << "ms" << std::endl;
    std::cout << "Efficiency (simple): " << (double)simpleAllocTime / (double)numObjects << "ms/object" << std::endl;
    std::cout << "Efficiency (default): " << (double)defaultAllocTime / (double)numObjects << "ms/object" << std::endl;
    std::cout << "Efficiency (std::allocator): " << (double)std::allocator<Object>::allocate(numObjects) / (double)numObjects << "ms/object" << std::endl;
}

int main() {
    testAllocators();
    return 0;
}
