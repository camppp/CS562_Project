#include <string>
#include <iostream>

std::string findNamespaceDeclaration(const std::string& code) {
    // Find the first opening brace in the code
    size_t openingBracePos = code.find_first_of('{');

    // If there is no opening brace, return an empty string
    if (openingBracePos == std::string::npos) {
        return "";
    }

    // Find the closing brace after the opening brace
    size_t closingBracePos = code.find_first_of('}', openingBracePos);

    // If there is no closing brace, return an empty string
    if (closingBracePos == std::string::npos) {
        return "";
    }

    // Extract the namespace name from the code
    std::string namespaceName = code.substr(openingBracePos + 1, closingBracePos - openingBracePos - 1);

    // Return the complete namespace declaration
    return "namespace " + namespaceName + " {\n";
}
