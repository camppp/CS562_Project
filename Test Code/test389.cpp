#include <iostream>
#include <string>

// Define the CHECK macro
#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            std::cerr << "Check failed at " << __FILE__ << ":" << __LINE__ << std::endl; \
        } \
    } while (0)

// Define the custom data type stobi
class CustomInteger {
public:
    int value;

    CustomInteger(const std::string& str) {
        value = std::stoi(str);
    }
};

int main() {
    CustomInteger a = CustomInteger("15");
    CustomInteger b = CustomInteger("100");

    // Use the CHECK macro to assert a condition
    CHECK(a.value > b.value);

    return 0;
}
