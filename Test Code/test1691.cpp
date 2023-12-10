#include <iostream>
#include <string>
#include <stdexcept>

class BadConversionException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Bad conversion";
    }
};

class JsonValue {
private:
    enum class Type { Boolean, String, Number };
    Type type;
    bool boolValue;
    std::string stringValue;
    double numberValue;

public:
    JsonValue(bool value) : type(Type::Boolean), boolValue(value) {}
    JsonValue(const std::string& value) : type(Type::String), stringValue(value) {}
    JsonValue(double value) : type(Type::Number), numberValue(value) {}

    std::string toString() const {
        if (type != Type::String) {
            throw BadConversionException();
        }
        return stringValue;
    }

    double toNumber() const {
        if (type != Type::Number) {
            throw BadConversionException();
        }
        return numberValue;
    }

    bool toBoolean() const {
        if (type != Type::Boolean) {
            throw BadConversionException();
        }
        return boolValue;
    }
};

int main() {
    JsonValue val1(true);
    JsonValue val2("Hello, World!");
    JsonValue val3(42.0);

    try {
        std::cout << val1.toString() << std::endl;  // Throws BadConversionException
    } catch (const BadConversionException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << val2.toNumber() << std::endl;  // Throws BadConversionException
    } catch (const BadConversionException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << val3.toBoolean() << std::endl;  // Throws BadConversionException
    } catch (const BadConversionException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
