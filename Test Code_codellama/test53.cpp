#include <fstream>
#include <iostream>
#include <string>

std::string getCopyrightHolder(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << filePath << std::endl;
        return "Unknown";
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.find("Copyright") != std::string::npos) {
            std::string copyrightHolder = line.substr(line.find("Copyright") + 10);
            return copyrightHolder;
        }
    }

    return "Unknown";
}
