#include <iostream>
#include <sstream>
#include <vector>

std::string indentText(const std::string& text, int numSpaces) {
    std::stringstream indentedText;
    std::stringstream ss(text);
    std::string line;

    while (std::getline(ss, line, '\n')) {
        indentedText << std::string(numSpaces, ' ') << line << "\n";
    }

    return indentedText.str();
}

int main() {
    std::string inputText = "Hello";
    int numSpaces = 4;
    std::string indented = indentText(inputText, numSpaces);
    std::cout << indented;  // Output: "    Hello"
    return 0;
}
