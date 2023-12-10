#include <iostream>
#include <string>

bool isValidName(const std::string& name) {
    if (name.empty() || name.length() > 255) {
        return false;
    }

    const std::string invalidChars = "*?:|\\/<>\".";
    for (char c : name) {
        if (invalidChars.find(c) != std::string::npos) {
            return false;
        }
    }

    return true;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << isValidName("my_file123") << std::endl;  // Output: true
    std::cout << isValidName("invalid*name") << std::endl;  // Output: false
    return 0;
}
