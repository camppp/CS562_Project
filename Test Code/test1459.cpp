#include <iostream>
#include <string>

bool validateCharacterLiteral(const std::string& input) {
    if (input.size() == 3 && input[0] == '\'' && input[2] == '\'') {
        // Check if the character within single quotes is valid
        char c = input[1];
        if (c >= 32 && c <= 126 && c != '\'') {
            return true;  // Valid character literal
        }
    }
    return false;  // Invalid character literal
}

int main() {
    std::cout << std::boolalpha;
    std::cout << validateCharacterLiteral("'a'") << std::endl;  // Output: true
    std::cout << validateCharacterLiteral("'ab'") << std::endl;  // Output: false
    return 0;
}
