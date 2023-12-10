#include <iostream>
#include <string>

int atoi(const std::string& str) {
    // Discard leading whitespaces
    size_t start = str.find_first_not_of(" ");
    if (start == std::string::npos) {
        return 0;
    }

    // Check if the next character is a plus or minus sign
    char sign = str[start];
    if (sign != '+' && sign != '-') {
        return 0;
    }

    // Check if the following characters are numerical digits
    size_t end = str.find_first_not_of("0123456789", start + 1);
    if (end == std::string::npos) {
        end = str.size();
    }

    // Convert the numerical digits into an integer
    std::string num = str.substr(start + 1, end - start - 1);
    int result = std::stoi(num);

    // Check for integer overflow
    if (result < std::numeric_limits<int>::min() || result > std::numeric_limits<int>::max()) {
        if (sign == '-') {
            return std::numeric_limits<int>::min();
        } else {
            return std::numeric_limits<int>::max();
        }
    }

    // Return the integer equivalent of the input string
    return result;
}
