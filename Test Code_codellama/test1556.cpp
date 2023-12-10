#include <exception>
#include <string>

class NotImplementedException : public std::exception {
public:
    NotImplementedException(const std::string& functionName) : functionName_(functionName) {}
    NotImplementedException(const std::string& functionName, int errorCode) : functionName_(functionName), errorCode_(errorCode) {}
    NotImplementedException(const std::string& functionName, int errorCode, const std::string& message) : functionName_(functionName), errorCode_(errorCode), message_(message) {}

    const char* what() const noexcept override {
        return "Not implemented";
    }

    const std::string& getFunctionName() const {
        return functionName_;
    }

    int getErrorCode() const {
        return errorCode_;
    }

    const std::string& getMessage() const {
        return message_;
    }

private:
    std::string functionName_;
    int errorCode_;
    std::string message_;
};
