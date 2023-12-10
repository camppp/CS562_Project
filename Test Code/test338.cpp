#include <iostream>
#include <string>

class Config {
public:
    Config(const std::string& value) : value_(value) {}
    std::string getValue() const { return value_; }
};

class String {
public:
    String(const std::string& value) : value_(value) {}
    std::string getValue() const { return value_; }
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

int main() {
    CustomComparator c;

    // Test cases
    BOOST_TEST(c == "World");
    BOOST_TEST(c == Config("World"));
    BOOST_TEST(c == String("World"));
    BOOST_TEST(c != "hello");
    BOOST_TEST(c != Config("hello"));
    BOOST_TEST(c == true);
    BOOST_TEST(c != false);
}
