#include <iostream>
#include <fstream>
#include <string>

int countPreprocessorDirectives(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return -1; // Error code for file open failure
    }

    std::string line;
    int directiveCount = 0;
    while (std::getline(file, line)) {
        if (!line.empty() && line[0] == '#') {
            directiveCount++;
        }
    }

    file.close();
    return directiveCount;
}

int main() {
    std::string filePath = "example.hpp";
    int result = countPreprocessorDirectives(filePath);
    if (result != -1) {
        std::cout << "Number of preprocessor directives: " << result << std::endl;
    }
    return 0;
}
