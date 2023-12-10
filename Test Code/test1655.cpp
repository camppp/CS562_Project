#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main() {
    std::ifstream file("example_header.hpp");
    std::string line;
    std::string constants;

    bool inConstantsSection = false;
    std::regex constantPattern("static const .*? ([A-Za-z_][A-Za-z0-9_]*)");

    while (std::getline(file, line)) {
        if (line.find("Constants exported from the class") != std::string::npos) {
            inConstantsSection = true;
            continue;
        }

        if (inConstantsSection) {
            std::smatch match;
            if (std::regex_search(line, match, constantPattern)) {
                constants += match[1].str() + "\n";
            }
        }
    }

    std::cout << "Extracted Constants:\n" << constants;
    return 0;
}
