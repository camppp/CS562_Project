++
#include <iostream>
#include <string>
#include <regex>

bool isValidFilePath(const std::string& filePath) {
    // Define the regular expression pattern to match invalid characters
    std::regex invalidChars("[<>:\"/\\|?*]");
    
    // Check for invalid characters in the file path
    if (std::regex_search(filePath, invalidChars)) {
        return false;
    }
    
    // Check for trailing space or period at the end of the file path
    if (filePath.back() == ' ' || filePath.back() == '.') {
        return false;
    }
    
    return true;
}

int main() {
    // Test cases
    std::cout << std::boolalpha;
    std::cout << isValidFilePath("C:\\Program Files\\file.txt") << std::endl;  // Output: true
    std::cout << isValidFilePath("C:\\Program Files\\<file>.txt") << std::endl;  // Output: false
    std::cout << isValidFilePath("C:\\Program Files\\file.txt ") << std::endl;  // Output: false
    return 0;
}
