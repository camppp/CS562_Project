#include <iostream>
#include <string>
#include <cctype>

bool isValidPreprocessorDirective(const std::string& directive) {
    if (directive.empty() || directive[0] != '#') {
        return false;
    }

    size_t pos = 1;
    while (pos < directive.size() && std::isspace(directive[pos])) {
        pos++;
    }

    if (pos == directive.size()) {
        return false;  // No keyword after '#'
    }

    while (pos < directive.size() && std::isalpha(directive[pos])) {
        pos++;
    }

    while (pos < directive.size() && std::isspace(directive[pos])) {
        pos++;
    }

    if (pos == directive.size() || directive[pos] == '\n') {
        return true;  // Valid preprocessor directive without parameters
    }

    if (directive[pos] == '(') {
        pos++;
        while (pos < directive.size() && directive[pos] != ')') {
            pos++;
        }
        if (pos == directive.size() || directive[pos] != ')') {
            return false;  // Unmatched parenthesis
        }
        pos++;
    }

    while (pos < directive.size() && std::isspace(directive[pos])) {
        pos++;
    }

    return pos == directive.size() || directive[pos] == '\n';
}
