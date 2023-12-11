#include <iostream>

template <typename T>
class CustomSharedPtr {
public:
    // Default constructor
    CustomSharedPtr() : ptr(nullptr), refCount(new int(0)) {}

    // Constructor with raw pointer
    CustomSharedPtr(T* ptr) : ptr(ptr), refCount(new int(1)) {}

    // Copy constructor
    CustomSharedPtr(const CustomSharedPtr& other) : ptr(other.ptr), refCount(other.refCount) {
        (*refCount)++;
    }

    // Assignment operator
    CustomSharedPtr& operator=(const CustomSharedPtr& other) {
        if (this != &other) {
            if (ptr != nullptr && --(*refCount) == 0) {
                delete ptr;
                delete refCount;
            }
            ptr = other.ptr;
            refCount = other.refCount;
            (*refCount)++;
        }
        return *this;
    }

    // Destructor
    ~CustomSharedPtr() {
        if (--(*refCount) == 0) {
            delete ptr;
            delete refCount;
        }
    }

    // Get raw pointer
    T* get() {
        return ptr;
    }

    // Get reference count
    int use_count() {
        return *refCount;
    }

private:
    T* ptr;
    int* refCount;
};

int main() {
    CustomSharedPtr<int> ptr1(new int(5));
    CustomSharedPtr<int> ptr2 = ptr1;
    std::cout << "ptr1 use count: " << ptr1.use_count() << std::endl;
    std::cout << "ptr2 use count: " << ptr2.use_count() << std::endl;
    return 0;
}
