#include <iostream>
#include <string>

// Complex number structure
struct FloatComplex {
    float real;
    float imag;
};

// Template class for error handling
template <typename T>
class ErrorClass {
public:
    void error(int errorCode) {
        std::string errorMessage;
        switch (errorCode) {
            case CL_INVALID_COMMAND_QUEUE:
                errorMessage = "Invalid command queue error";
                break;
            // Add more cases for other error codes as needed
            default:
                errorMessage = "Unknown error";
                break;
        }
        std::cout << "Error: " << errorMessage << std::endl;
    }
};

int main() {
    ErrorClass<HbmvMetod<FloatComplex>> ec;
    ec.error(CL_INVALID_COMMAND_QUEUE);
    return 0;
}
