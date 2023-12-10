#include <iostream>
#include <string>

class StringBuilder {
public:
    void appendLiteral(const char* str) {
        message += str;
    }

    void appendNumber(unsigned num) {
        message += std::to_string(num);
    }

    void appendString(const std::string& str) {
        message += str;
    }

    std::string getMessage() const {
        return message;
    }

private:
    std::string message;
};

void appendErrorMessage(StringBuilder& builder, unsigned argumentIndex, const char* argumentName, const char* interfaceName, const char* functionName) {
    builder.appendLiteral("Argument ");
    builder.appendNumber(argumentIndex);
    builder.appendLiteral(": '");
    builder.appendString(argumentName);
    builder.appendLiteral("' is invalid in ");
    builder.appendString(interfaceName);
    builder.appendLiteral(".");
    builder.appendString(functionName);
    builder.appendLiteral(".");
}

int main() {
    StringBuilder errorBuilder;
    unsigned argumentIndex = 2;
    const char* argumentName = "value";
    const char* interfaceName = "Math";
    const char* functionName = "calculate";

    appendErrorMessage(errorBuilder, argumentIndex, argumentName, interfaceName, functionName);
    std::cout << errorBuilder.getMessage() << std::endl;

    return 0;
}
