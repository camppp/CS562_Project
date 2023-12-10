#include <iostream>
#include <vector>
#include <cctype>

void convertHexToDecimal(std::istream& is, std::vector<int>& decimalValues) {
    char c;
    decimalValues.clear();

    // Ignore leading whitespace characters
    while (isspace(is.peek())) {
        is.get();
    }

    while (is.get(c)) {
        if (c >= '0' && c <= '9') {
            decimalValues.push_back(c - '0');  // Convert '0' to '9' to decimal
        } else if (c >= 'A' && c <= 'F') {
            decimalValues.push_back(c - 'A' + 10);  // Convert 'A' to 'F' to decimal
        }
    }
}

int main() {
    std::vector<int> decimalValues;
    convertHexToDecimal(std::cin, decimalValues);

    // Output the converted decimal values
    for (int val : decimalValues) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
