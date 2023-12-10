#include <iostream>
#include <fstream>
#include <string>
#include <exception>

class CustomErrorHandler {
private:
    std::ofstream errorLogFile;
    std::string lastErrorMessage;

public:
    CustomErrorHandler(const std::string& logFileName) : errorLogFile(logFileName, std::ios::app) {
        if (!errorLogFile.is_open()) {
            throw std::runtime_error("Failed to open error log file");
        }
    }

    ~CustomErrorHandler() {
        errorLogFile.close();
    }

    void LogError(const std::string& errorMessage) {
        errorLogFile << "Error: " << errorMessage << std::endl;
        std::cerr << "Error: " << errorMessage << std::endl;
        lastErrorMessage = errorMessage;
    }

    std::string GetLastErrorMessage() const {
        return lastErrorMessage;
    }
};

// Usage example
int main() {
    try {
        // Initialize custom error handler
        CustomErrorHandler errorHandler("error.log");

        // Simulate an error during image processing
        throw std::runtime_error("Image processing error");

    } catch (const std::exception& error) {
        CustomErrorHandler errorHandler("error.log");
        errorHandler.LogError(error.what());
        return EXIT_FAILURE;
    }

    return 0;
}
