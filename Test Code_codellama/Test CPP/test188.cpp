#include <iostream>

template <typename T>
class MySmartPointer {
public:
    MySmartPointer(T* ptr) : ptr_(ptr) {}

    T* operator*() { return ptr_; }
    T* operator->() { return ptr_; }

    T* release() {
        T* temp = ptr_;
        ptr_ = nullptr;
        return temp;
    }

    ~MySmartPointer() {
        delete ptr_;
    }

private:
    T* ptr_;
};

int main() {
    int* p = new int(5);
    MySmartPointer<int> sp(p);

    std::cout << *sp << std::endl; // prints 5
    std::cout << sp->get() << std::endl; // prints 5

    int* q = sp.release();
    std::cout << *q << std::endl; // prints 5

    delete q;

    return 0;
}
