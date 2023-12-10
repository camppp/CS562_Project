#include <iostream>
#include <string>

class CustomOutputStream {
public:
    // Overload the insertion operator for integers
    // Format: "Integer: <value>"
    CustomOutputStream& operator<<(int value) {
        std::cout << "Integer: " << value;
        return *this;
    }

    // Overload the insertion operator for strings
    // Format: "String: <value>"
    CustomOutputStream& operator<<(const std::string& value) {
        std::cout << "String: " << value;
        return *this;
    }
};

int main() {
    CustomOutputStream os;
    os << 10 << "Hello";
    return 0;
}
