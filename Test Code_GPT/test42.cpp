#include <iostream>
#include <fstream>
#include <regex>
#include <string>

std::string extractCopyrightHolder(const std::string& filePath) {
    std::ifstream file(filePath);
    
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << std::endl;
        return "Unknown";
    }

    std::string line;
    std::string commentBlock;
    bool inCommentBlock = false;

    // Read the file line by line
    while (std::getline(file, line)) {
        // Check if the line starts with a comment block
        if (std::regex_match(line, std::regex(R"(\s*/\*.*\*/\s*)"))) {
            commentBlock += line + "\n";
            inCommentBlock = true;
        } else if (inCommentBlock) {
            // Check if the comment block ends
            if (line.find("*/") != std::string::npos) {
                commentBlock += line + "\n";
                inCommentBlock = false;
                break;
            } else {
                commentBlock += line + "\n";
            }
        }
    }

    // Extract the copyright holder's name using regular expression
    std::regex pattern(R"(Copyright[^\n]*\n[^A-Za-z0-9_]*([A-Za-z0-9_ ]+))");
    std::smatch match;

    if (std::regex_search(commentBlock, match, pattern)) {
        return match[1].str();
    }

    return "Unknown";
}

int main() {
    std::string filePath = "path/to/your/source/file.cpp";
    std::string copyrightHolder = extractCopyrightHolder(filePath);

    std::cout << "Copyright Holder: " << copyrightHolder << std::endl;

    return 0;
}
