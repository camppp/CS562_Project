#include <string>
#include <cctype>
#include <cstdlib>

bool isValidProjectPath(const std::string& projectPath) {
    // Check if the project path is empty
    if (projectPath.empty()) {
        return false;
    }

    // Check if the project path contains any whitespace characters
    if (std::any_of(projectPath.begin(), projectPath.end(), [](char c) { return std::isspace(c); })) {
        return false;
    }

    // Check if the project path starts with a valid drive letter followed by a colon
    if (!std::isalpha(projectPath[0]) || projectPath[1] != ':') {
        return false;
    }

    // Check if the project path is followed by a valid directory path
    if (!std::isalnum(projectPath[2]) && projectPath[2] != '/' && projectPath[2] != '\\') {
        return false;
    }

    // Check if the project path ends with a valid file or directory name
    if (!std::isalnum(projectPath.back()) && projectPath.back() != '.' && projectPath.back() != '_') {
        return false;
    }

    return true;
}
