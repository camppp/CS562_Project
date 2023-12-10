#include <iostream>
#include <fstream>
#include <string>

int countEndifDirectives(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return -1;
    }

    std::string line;
    int count = 0;
    while (std::getline(file, line)) {
        size_t pos = line.find("#endif");
        while (pos != std::string::npos) {
            if (pos == 0 || line[pos - 1] == ' ' || line[pos - 1] == '\t') {
                count++;
            }
            pos = line.find("#endif", pos + 1);
        }
    }

    file.close();
    return count;
}

int main() {
    std::string filename = "example.cpp";  // Replace with the actual filename
    int occurrences = countEndifDirectives(filename);
    if (occurrences >= 0) {
        std::cout << occurrences << std::endl;
    }
    return 0;
}
