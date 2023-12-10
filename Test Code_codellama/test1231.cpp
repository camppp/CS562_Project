#include <iostream>
#include <vector>
#include <string>

void convertHexToDecimal(std::istream& is, std::vector<int>& decimalValues) {
    // Read the input stream character by character
    std::string input;
    is >> input;

    // Ignore any leading whitespace characters
    size_t start = input.find_first_not_of(" \t\n\r");
    input = input.substr(start);

    // Convert the hexadecimal digits to decimal values
    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];
        if (c >= '0' && c <= '9') {
            decimalValues.push_back(c - '0');
        } else if (c >= 'A' && c <= 'F') {
            decimalValues.push_back(c - 'A' + 10);
        }
    }
}
