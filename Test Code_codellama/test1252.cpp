#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int countWordOccurrences(const std::string& filename, const std::string& word) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: unable to open file " << filename << std::endl;
        return -1;
    }

    int count = 0;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        while (iss >> token) {
            if (token == word) {
                count++;
            }
        }
    }

    return count;
}
