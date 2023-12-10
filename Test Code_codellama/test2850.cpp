#include <iostream>
#include <string>

class PointerNullException : public std::exception {
public:
    PointerNullException(const std::string& message) : std::exception(message) {}
};

int main() {
    int* p = nullptr;
    try {
        if (p == nullptr) {
            throw PointerNullException("Pointer unexpectedly became nullptr");
        }
    } catch (const PointerNullException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
