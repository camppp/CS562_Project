#include <iostream>
#include <fstream>
#include <string>

int countCustomCodeLines(const std::string& fileContent) {
    int customCodeLines = 0;
    std::string line;
    std::istringstream iss(fileContent);
    while (std::getline(iss, line)) {
        if (line.find("// Custom code") != std::string::npos) {
            customCodeLines++;
        }
    }
    return customCodeLines;
}
