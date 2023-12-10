#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

// Function to extract a substring of length 'length' from 'hex_str'
std::string subString(const std::string& hex_str, int length) {
    return hex_str.substr(0, length);
}

// Function to convert a hexadecimal string to decimal
int hex2dec(const std::string& hex_str) {
    int decimal_value;
    std::stringstream ss;
    ss << std::hex << hex_str;
    ss >> decimal_value;
    return decimal_value;
}

int main() {
    std::string hex_str = "1A2B3C4D";
    std::string sub_hex_str = subString(hex_str, 6);
    std::cout << hex2dec(sub_hex_str) << std::endl;  // This line should print the decimal value of the extracted substring
    return 0;
}
