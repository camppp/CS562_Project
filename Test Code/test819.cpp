#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

namespace mbgl {
    std::string reverseWords(const std::string& input) {
        std::istringstream iss(input);
        std::string word, result;
        while (iss >> word) {
            std::reverse(word.begin(), word.end());
            result = (result.empty()) ? word : word + " " + result;
        }
        return result;
    }
} // namespace mbgl
