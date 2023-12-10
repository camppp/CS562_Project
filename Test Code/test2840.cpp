#include <iostream>
#include <chrono>
#include <vector>
#include <memory>

// Define the GenericTestObject type for memory allocation
struct GenericTestObject {
    // Define the properties of the test object
    // ...
};

namespace DS {
    // Define the custom memory allocator class AllocatorSimple
    template <class T>
    class AllocatorSimple {
    public:
        // Implement the memory allocation and deallocation functions
        T* allocate(std::size_t n) {
            return static_cast<T*>(::operator new(n * sizeof(T)));
        }

        void deallocate(T* p, std::size_t n) {
            ::operator delete(p);
        }
    };

    // Define the custom memory allocator class AllocatorDefault
    template <class T>
    class AllocatorDefault {
    public:
        // Implement the memory allocation and deallocation functions
        T* allocate(std::size_t n) {
            return static_cast<T*>(::operator new(n * sizeof(T)));
        }

        void deallocate(T* p, std::size_t n) {
            ::operator delete(p);
        }
    };

    namespace TESTS {
        // Test function to compare the performance of custom allocators with std::allocator
        template <class Allocator, class T, std::size_t element_size>
        void testAllocator() {
            // Measure the time taken for memory allocation using the custom allocator
            auto start = std::chrono::high_resolution_clock::now();
            Allocator allocator;
            T* obj = allocator.allocate(element_size);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> allocTime = end - start;
            std::cout << "Time taken for allocation using custom allocator: " << allocTime.count() << " seconds" << std::endl;

            // Measure the time taken for memory deallocation using the custom allocator
            start = std::chrono::high_resolution_clock::now();
            allocator.deallocate(obj, element_size);
            end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> deallocTime = end - start;
            std::cout << "Time taken for deallocation using custom allocator: " << deallocTime.count() << " seconds" << std::endl;
        }

        // Function to compare the performance of different allocators
        template <class Allocator1, class Allocator2, class T, std::size_t element_size>
        void compareAllocators() {
            std::cout << "Comparing performance of custom allocator with std::allocator" << std::endl;
            testAllocator<Allocator1, T, element_size>();
            testAllocator<Allocator2, T, element_size>();
        }
    }  // namespace TESTS
}  // namespace DS

int main() {
    constexpr std::size_t element_size = 1000;  // Define the size of the test object

    // Compare the performance of custom allocators with std::allocator for GenericTestObject
    DS::TESTS::compareAllocators<std::allocator<GenericTestObject>, DS::AllocatorSimple<GenericTestObject>, GenericTestObject, element_size>();
    DS::TESTS::compareAllocators<std::allocator<GenericTestObject>, DS::AllocatorDefault<GenericTestObject>, GenericTestObject, element_size>();

    return 0;
}
