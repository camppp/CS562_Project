#include <iostream>
#include <stdexcept>

#define VALIDATE_NOT_NULL(result) \
    if (result == nullptr) { \
        throw std::runtime_error("Null pointer exception"); \
    }

void processData(int* data) {
    VALIDATE_NOT_NULL(data);
    // If the pointer is not null, proceed with further operations
    std::cout << "Processing data: " << *data << std::endl;
}

int main() {
    int* ptr = new int(10);
    processData(ptr);  // This will print "Processing data: 10"
    
    int* nullPtr = nullptr;
    try {
        processData(nullPtr);  // This will throw a std::runtime_error with the message "Null pointer exception"
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    delete ptr;
    return 0;
}
