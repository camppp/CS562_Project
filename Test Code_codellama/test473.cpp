#include <iostream>
#include <string>
#include <unordered_set>

std::unordered_set<std::string> extractFileExtensions(const std::vector<std::string>& filePaths) {
    std::unordered_set<std::string> extensions;
    for (const std::string& filePath : filePaths) {
        size_t dotPos = filePath.find_last_of('.');
        if (dotPos != std::string::npos && dotPos != filePath.length() - 1) {
            extensions.insert(filePath.substr(dotPos + 1));
        } else if (dotPos == std::string::npos) {
            extensions.insert("");
        }
    }
    return extensions;
}
