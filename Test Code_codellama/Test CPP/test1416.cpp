#include <iostream>
#include <cstdlib>

class ErrorHandler {
public:
    void handleError(int errorCode, const std::string& errorMessage) {
        if (errorCode == 0) {
            std::cerr << "Error: " << errorMessage << std::endl;
            std::exit(1);
        } else {
            std::cerr << "Error: " << errorMessage << std::endl;
        }
    }
};

int main() {
    ErrorHandler errorHandler;
    errorHandler.handleError(0, "Custom error message 1");
    errorHandler.handleError(1, "Custom error message 2");
    return 0;
}
