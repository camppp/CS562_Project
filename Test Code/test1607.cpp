#include <fstream>
#include <iostream>
#include <string>

int countPreprocessorDirectives(const std::string& filePath) {
    std::ifstream file(filePath);
    int count = 0;
    std::string line;
    while (std::getline(file, line)) {
        if (line.find("#") == 0) {
            count++;
        }
    }
    return count;
}
