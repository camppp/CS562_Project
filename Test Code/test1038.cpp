#include <iostream>
#include <map>

// Define a MemoryManager class to handle memory allocation and deallocation
class MemoryManager {
private:
    std::map<void*, size_t> memoryMap; // Map to store allocated memory addresses and their sizes

public:
    // Allocate memory for an instance of a class or struct
    void* allocate(size_t size) {
        void* ptr = new char[size];
        memoryMap[ptr] = size;
        return ptr;
    }

    // Deallocate memory for an instance of a class or struct
    void deallocate(void* ptr) {
        if (memoryMap.find(ptr) != memoryMap.end()) {
            delete[] static_cast<char*>(ptr);
            memoryMap.erase(ptr);
        }
    }

    // Allocate memory for a pointer to a class or struct
    template <typename T>
    T* allocatePointer() {
        return new T;
    }

    // Deallocate memory for a pointer to a class or struct
    template <typename T>
    void deallocatePointer(T* ptr) {
        delete ptr;
    }

    // Destructor to ensure all allocated memory is properly deallocated
    ~MemoryManager() {
        for (auto const& pair : memoryMap) {
            delete[] static_cast<char*>(pair.first);
        }
        memoryMap.clear();
    }
};

int main() {
    MemoryManager memManager;

    // Allocate memory for an instance of class_A
    class_A* a = static_cast<class_A*>(memManager.allocate(sizeof(class_A)));

    // Allocate memory for a pointer to class_A
    class_A* pa = memManager.allocatePointer<class_A>();

    // Allocate memory for an instance of struct_S
    struct_S* s = static_cast<struct_S*>(memManager.allocate(sizeof(struct_S)));

    // Allocate memory for a pointer to struct_S
    struct_S* ps = memManager.allocatePointer<struct_S>();

    // Deallocate memory for the instances and pointers
    memManager.deallocate(a);
    memManager.deallocatePointer(pa);
    memManager.deallocate(s);
    memManager.deallocatePointer(ps);

    return 0;
}
