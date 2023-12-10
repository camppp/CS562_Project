#include <exception>
#include <string>
#include <sstream>

class NotImplementedException : public std::exception {
private:
    std::string functionName;
    int errorCode;
    std::string message;

public:
    NotImplementedException(const std::string& funcName)
        : functionName(funcName), errorCode(0), message("") {}

    NotImplementedException(const std::string& funcName, int errCode)
        : functionName(funcName), errorCode(errCode), message("") {}

    NotImplementedException(const std::string& funcName, int errCode, const std::string& msg)
        : functionName(funcName), errorCode(errCode), message(msg) {}

    const char* what() const noexcept override {
        std::stringstream ss;
        ss << "Function '" << functionName << "' is not implemented";
        if (errorCode != 0) {
            ss << " (Error code: " << errorCode << ")";
        }
        if (!message.empty()) {
            ss << ": " << message;
        }
        return ss.str().c_str();
    }
};

// Test function to verify the functionality of NotImplementedException
void testNotImplementedException() {
    try {
        throw NotImplementedException("not_implemented");
    } catch (const NotImplementedException& e) {
        // Verify the exception message
        assert(std::string(e.what()) == "Function 'not_implemented' is not implemented");
    }

    try {
        throw NotImplementedException("test_func", 123);
    } catch (const NotImplementedException& e) {
        // Verify the exception message
        assert(std::string(e.what()) == "Function 'test_func' is not implemented (Error code: 123)");
    }

    try {
        throw NotImplementedException("test_func", 456, "Check error message");
    } catch (const NotImplementedException& e) {
        // Verify the exception message
        assert(std::string(e.what()) == "Function 'test_func' is not implemented (Error code: 456): Check error message");
    }
}
