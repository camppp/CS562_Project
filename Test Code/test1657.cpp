#include <iostream>
#include <exception>

class CustomException : public std::exception {
public:
    CustomException(const char* message) : std::exception(message) {}
};

void throwCustomException() {
    throw CustomException("Custom exception occurred");
}

int main() {
    try {
        throwCustomException();
    } catch (const CustomException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
