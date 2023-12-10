#include <iostream>
#include <exception>
#include <string>

// Custom exception class for protocol-related errors
class ProtocolException : public std::exception {
private:
    std::string errorMessage;

public:
    // Constructor to initialize the error message
    ProtocolException(const std::string& message) : errorMessage(message) {}

    // Override the what() method to provide the error message
    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};

// Sample network communication function demonstrating the usage of ProtocolException
void performNetworkCommunication() {
    // Simulate a protocol-related error
    bool protocolErrorOccurred = true;

    try {
        if (protocolErrorOccurred) {
            // Throw a ProtocolException with a custom error message
            throw ProtocolException("Protocol error occurred during network communication");
        } else {
            // Perform normal network communication
            std::cout << "Network communication successful" << std::endl;
        }
    } catch (const ProtocolException& e) {
        // Catch and handle the ProtocolException
        std::cerr << "Caught ProtocolException: " << e.what() << std::endl;
        // Perform error handling or cleanup actions
    }
}

int main() {
    // Call the sample network communication function
    performNetworkCommunication();

    return 0;
}
