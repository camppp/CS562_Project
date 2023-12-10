#include <iostream>
#include <string>
#include <sstream>

std::string reverseWords(const std::string& input) {
    std::istringstream iss(input);
    std::string word;
    std::string reversedString;

    while (iss >> word) {
        if (!reversedString.empty()) {
            reversedString = word + " " + reversedString;
        } else {
            reversedString = word;
        }
    }

    return reversedString;
}

int main() {
    std::string input = "  Hello   World!  ";
    std::string reversed = reverseWords(input);
    std::cout << "Reversed string: " << reversed << std::endl;
    return 0;
}
