#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> braceExpansion(const std::string& input) {
    std::vector<std::string> result;
    std::string::size_type start = 0;
    std::string::size_type end = input.find('{');
    while (end != std::string::npos) {
        // Add the prefix before the first curly brace
        result.push_back(input.substr(start, end - start));
        // Find the closing curly brace
        end = input.find('}', end);
        if (end == std::string::npos) {
            // No closing curly brace found, return an empty vector
            return result;
        }
        // Add the options inside the curly braces
        std::string options = input.substr(end + 1, end - start - 1);
        std::vector<std::string> options_vector = split(options, ',');
        for (const std::string& option : options_vector) {
            result.push_back(input.substr(0, end) + option + input.substr(end + 1));
        }
        // Update the start index to the character after the closing curly brace
        start = end + 1;
        end = input.find('{', end + 1);
    }
    // Add the suffix after the last curly brace
    result.push_back(input.substr(start));
    return result;
}

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string::size_type start = 0;
    std::string::size_type end = str.find(delimiter);
    while (end != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delimiter, start);
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
