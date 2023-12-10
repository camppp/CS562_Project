#include <string>

std::string removeCharacter(const std::string& original, char toRemove) {
    std::string result;
    for (char c : original) {
        if (std::tolower(c) != std::tolower(toRemove)) {
            result += c;
        }
    }
    return result;
}
