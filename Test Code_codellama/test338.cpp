#include <iostream>
#include <string>

class Config {
public:
    Config(const std::string& value) : value_(value) {}
    std::string getValue() const { return value_; }
private:
    std::string value_;
};

class String {
public:
    String(const std::string& value) : value_(value) {}
    std::string getValue() const { return value_; }
private:
    std::string value_;
};

class CustomComparator {
public:
    bool operator==(const std::string& str) const {
        return str == "World";
    }

    bool operator==(const Config& config) const {
        return config.getValue() == "World";
    }

    bool operator==(const String& strObj) const {
        return strObj.getValue() == "World";
    }

    bool operator!=(const std::string& str) const {
        return str != "hello";
    }

    bool operator!=(const Config& config) const {
        return config.getValue() != "hello";
    }

    bool operator==(bool b) const {
        return b;
    }
};
