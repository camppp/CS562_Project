class SmartPtr {
private:
    int* ptr;

public:
    // Constructor to initialize the smart pointer with a dynamically allocated object
    SmartPtr(int* p) : ptr(p) {}

    // Destructor to release the memory of the managed object
    ~SmartPtr() {
        delete ptr;
    }

    // Overload the dereference operator (*) to access the managed object
    int& operator*() {
        return *ptr;
    }

    // Overload the arrow operator (->) to access members of the managed object
    int* operator->() {
        return ptr;
    }

    // Function to reassign the smart pointer to manage a different object
    void reset(int* p) {
        delete ptr;
        ptr = p;
    }
};
