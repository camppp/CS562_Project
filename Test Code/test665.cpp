#include <iostream>
#include <exception>

class LibraryException : public std::exception {
public:
    explicit LibraryException(const char* message) : std::exception(message) {}
};

void libraryFunction() {
    // Simulate an error condition.
    throw LibraryException("Error: Library function encountered an issue.");
}

int main() {
    try {
        libraryFunction();
    } catch (const LibraryException& e) {
        std::cout << "Caught LibraryException: " << e.what() << std::endl;
    }
    return 0;
}
