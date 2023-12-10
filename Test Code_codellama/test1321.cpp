#include <fstream>
#include <iostream>
#include <string>

int countNamespaceOccurrences(const std::string& filePath, const std::string& targetNamespace) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return -1;
    }

    int count = 0;
    std::string line;
    while (std::getline(file, line)) {
        if (line.find("namespace " + targetNamespace) != std::string::npos) {
            count++;
        }
    }

    file.close();
    return count;
}
