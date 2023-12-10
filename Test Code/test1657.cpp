#include <iostream>
#include <exception>

class CustomException : public std::exception {
public:
    CustomException(const char* message) : errorMessage(message) {}

    const char* what() const noexcept override {
        return errorMessage;
    }

private:
    const char* errorMessage;
};

void throwCustomException() {
    throw CustomException("Custom exception occurred");
}

int main() {
    try {
        throwCustomException();
    } catch (const CustomException& e) {
        std::cerr << "Custom exception caught: " << e.what() << std::endl;
    }
    return 0;
}
