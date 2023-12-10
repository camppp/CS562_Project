#include <string>
#include <stdexcept>

class JsonValue {
public:
    JsonValue(const std::string& value) : value_(value) {}

    std::string toString() const {
        if (isString()) {
            return value_;
        } else {
            throw std::bad_conversion_exception("Cannot convert to string");
        }
    }

    double toNumber() const {
        if (isNumber()) {
            return std::stod(value_);
        } else {
            throw std::bad_conversion_exception("Cannot convert to number");
        }
    }

    bool toBoolean() const {
        if (isBoolean()) {
            return std::stoi(value_) != 0;
        } else {
            throw std::bad_conversion_exception("Cannot convert to boolean");
        }
    }

private:
    std::string value_;

    bool isString() const {
        return value_.find_first_not_of("\"") == std::string::npos;
    }

    bool isNumber() const {
        return value_.find_first_not_of("0123456789") == std::string::npos;
    }

    bool isBoolean() const {
        return value_ == "true" || value_ == "false";
    }
};
