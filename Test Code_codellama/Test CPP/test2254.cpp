#include <string>
#include <cctype>

bool isValidPreprocessorDirective(const std::string& directive) {
    // Check if the directive starts with a '#' symbol
    if (directive.empty() || directive[0] != '#') {
        return false;
    }

    // Check if the directive is followed by a keyword
    std::string keyword = directive.substr(1);
    if (keyword.empty()) {
        return false;
    }

    // Check if the keyword is a valid preprocessor directive
    if (keyword == "ifdef" || keyword == "ifndef" || keyword == "define" || keyword == "include") {
        return true;
    }

    // Check if the directive is followed by optional parameters or arguments
    std::string::size_type pos = directive.find_first_of(" \t");
    if (pos != std::string::npos) {
        return true;
    }

    // Check if the directive is followed by a newline character
    pos = directive.find_first_of("\n");
    if (pos != std::string::npos) {
        return true;
    }

    return false;
}
