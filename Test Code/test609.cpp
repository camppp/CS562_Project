#include <iostream>
#include <string>
#include <stdexcept>

class ProtocolException : public std::exception {
public:
    ProtocolException(const std::string& message) : message_(message) {}

    const char* what() const noexcept override {
        return message_.c_str();
    }

private:
    std::string message_;
};

void sendData(const std::string& data) {
    try {
        // Send data over the network
        // ...
    } catch (const ProtocolException& e) {
        std::cerr << "Protocol error: " << e.what() << std::endl;
    }
}

int main() {
    try {
        sendData("Hello, world!");
    } catch (const ProtocolException& e) {
        std::cerr << "Protocol error: " << e.what() << std::endl;
    }

    return 0;
}
