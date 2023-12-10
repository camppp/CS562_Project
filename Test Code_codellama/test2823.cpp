#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Error: File not found." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Convert the line to lowercase
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);

        // Remove punctuation and whitespace
        line.erase(std::remove_if(line.begin(), line.end(), [](char c) {
            return !std::isalnum(c);
        }), line.end());

        // Check if the phrase is in the line
        if (line.find("this") != std::string::npos) {
            std::cout << "Phrase found: " << line.find("this") << std::endl;
        }
    }

    return 0;
}
