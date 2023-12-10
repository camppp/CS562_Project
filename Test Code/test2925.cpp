#include <iostream>
#include <string>
#include <regex>

bool isValidProjectPath(const std::string& projectPath) {
    // Check if the project path is not empty
    if (projectPath.empty()) {
        return false;
    }

    // Check if the project path contains any whitespace characters
    if (std::any_of(projectPath.begin(), projectPath.end(), ::isspace)) {
        return false;
    }

    // Define a regular expression pattern to match the project path format
    std::regex pattern(R"([A-Za-z]:[\\\/][\w\s.-]+[\\\/][\w\s.-]+)");

    // Check if the project path matches the defined pattern
    return std::regex_match(projectPath, pattern);
}

int main() {
    // Test cases
    std::string path1 = "C:/Projects/MyProject";
    std::string path2 = "D:\\Documents\\Code\\Main.cpp";
    std::string path3 = "E:/Data Files/Report.docx";

    std::cout << std::boolalpha;
    std::cout << "Path 1 is valid: " << isValidProjectPath(path1) << std::endl;  // Output: true
    std::cout << "Path 2 is valid: " << isValidProjectPath(path2) << std::endl;  // Output: true
    std::cout << "Path 3 is valid: " << isValidProjectPath(path3) << std::endl;  // Output: false

    return 0;
}
