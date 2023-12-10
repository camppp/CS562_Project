#include <iostream>
#include <string>

std::string alignNamespaceBraces(const std::string& code) {
    std::string alignedCode;
    int indentationLevel = 0;

    for (char c : code) {
        if (c == '{') {
            alignedCode += "{\n";
            indentationLevel++;
            alignedCode += std::string(4 * indentationLevel, ' ');
        } else if (c == '}') {
            indentationLevel--;
            alignedCode += "\n" + std::string(4 * indentationLevel, ' ') + "}\n";
            alignedCode += std::string(4 * indentationLevel, ' ');
        } else {
            alignedCode += c;
        }
    }

    return alignedCode;
}

int main() {
    std::string inputCode = "namespace vgc {\nnamespace widgets {\n}\n}\n";
    std::string alignedCode = alignNamespaceBraces(inputCode);
    std::cout << alignedCode;
    return 0;
}
