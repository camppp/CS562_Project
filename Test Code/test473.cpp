#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

std::unordered_set<std::string> extractFileExtensions(const std::vector<std::string>& filePaths) {
    std::unordered_set<std::string> extensions;
    for (const std::string& filePath : filePaths) {
        size_t dotPos = filePath.find_last_of('.');
        if (dotPos != std::string::npos && dotPos != filePath.length() - 1) {
            extensions.insert(filePath.substr(dotPos + 1));
        } else if (dotPos != std::string::npos && dotPos == filePath.length() - 1) {
            extensions.insert("");  // Empty extension
        } else {
            extensions.insert("no_extension");  // File with no extension
        }
    }
    return extensions;
}

int main() {
    std::vector<std::string> files = {
        "document.txt",
        "image.png",
        "script.js",
        "data.csv",
        "archive.tar.gz",
        "config"
    };

    std::unordered_set<std::string> uniqueExtensions = extractFileExtensions(files);

    std::cout << "Unique file extensions:" << std::endl;
    for (const std::string& ext : uniqueExtensions) {
        std::cout << ext << std::endl;
    }

    return 0;
}
