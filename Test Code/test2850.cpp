#include <iostream>
#include <exception>

class PointerNullException : public std::exception {
public:
    PointerNullException(const char* message) : m_message(message) {}

    const char* what() const noexcept override {
        return m_message;
    }

private:
    const char* m_message;
};

void processPointer(int* ptr) {
    if (ptr == nullptr) {
        throw PointerNullException("Pointer was unexpectedly nullptr");
    } else {
        // Process the pointer
        std::cout << "Pointer is valid" << std::endl;
    }
}

int main() {
    int* ptr1 = new int(5);
    int* ptr2 = nullptr;

    try {
        processPointer(ptr1); // No exception thrown
        processPointer(ptr2); // Exception thrown
    } catch (const PointerNullException& e) {
        std::cerr << "PointerNullException caught: " << e.what() << std::endl;
    }

    delete ptr1;

    return 0;
}
