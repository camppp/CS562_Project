#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::vector<std::string>> extractRestrictions(const std::string& filePath) {
    std::ifstream file(filePath);
    std::vector<std::vector<std::string>> restrictionsCollection;
    std::vector<std::string> currentRestrictions;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (!line.empty()) {
                currentRestrictions.push_back(line);
            } else if (!currentRestrictions.empty()) {
                restrictionsCollection.push_back(currentRestrictions);
                currentRestrictions.clear();
            }
        }
        if (!currentRestrictions.empty()) {
            restrictionsCollection.push_back(currentRestrictions);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filePath << std::endl;
    }

    return restrictionsCollection;
}

int main() {
    std::vector<std::vector<std::string>> extractedRestrictions = extractRestrictions("license_agreements.txt");
    for (const auto& restrictions : extractedRestrictions) {
        for (const auto& restriction : restrictions) {
            std::cout << restriction << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
