c++
#include <string>
#include <cctype>

bool isValidFilePath(const std::string& filePath) {
    // Check if the file path is empty
    if (filePath.empty()) {
        return false;
    }

    // Check if the file path contains any invalid characters
    for (char c : filePath) {
        if (c == '<' || c == '>' || c == ':' || c == '"' || c == '/' || c == '\\' || c == '|' || c == '?' || c == '*') {
            return false;
        }
    }

    // Check if the file path ends with a space or a period
    if (filePath.back() == ' ' || filePath.back() == '.') {
        return false;
    }

    return true;
}
