#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter a Unicode string: ";
    std::getline(std::cin, input);

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (c == '\\') {
            // Handle escape sequences
            if (input[i + 1] == 'u') {
                // Unicode escape sequence
                std::cout << "\\u" << std::hex << (int)input[i + 2] << std::dec << std::endl;
                i += 2;
            } else if (input[i + 1] == 'x') {
                // Hexadecimal escape sequence
                std::cout << "\\x" << std::hex << (int)input[i + 2] << std::dec << std::endl;
                i += 2;
            } else {
                // Unknown escape sequence
                std::cout << "Unknown escape sequence: \\" << input[i + 1] << std::endl;
            }
        } else {
            // Print the code point value of the character
            std::cout << "Code point value: " << (int)c << std::endl;
        }
    }

    return 0;
}
