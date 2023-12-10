#include <iostream>

template <typename T>
class CustomUniquePtr {
public:
    explicit CustomUniquePtr(T* ptr) : ptr_(ptr) {}

    T& operator*() const {
        return *ptr_;
    }

    T* operator->() const {
        return ptr_;
    }

    T* release() {
        T* released_ptr = ptr_;
        ptr_ = nullptr;
        return released_ptr;
    }

    ~CustomUniquePtr() {
        delete ptr_;
    }

private:
    T* ptr_;
};

int main() {
    CustomUniquePtr<int> ptr(new int(42));
    std::cout << *ptr << std::endl;  // Output: 42
    *ptr = 100;
    std::cout << *ptr << std::endl;  // Output: 100

    int* released_ptr = ptr.release();
    if (ptr == nullptr) {
        std::cout << "Smart pointer released the resource" << std::endl;
    }

    delete released_ptr;  // Manually delete the released resource
    return 0;
}
