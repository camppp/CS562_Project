#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int validateFastaFile(const std::string& filePath, int expectedSequenceCount) {
    try {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::cerr << "Error: Unable to open file " << filePath << "\n";
            return -1;
        }

        std::string line;
        int sequenceCount = 0;
        while (std::getline(file, line)) {
            if (line.empty()) continue;  // Skip empty lines
            if (line[0] == '>') sequenceCount++;  // Count lines starting with '>'
        }

        if (sequenceCount != expectedSequenceCount) {
            std::cerr << "Invalid fasta file: must have " << expectedSequenceCount << " sequences.\n";
            return -1;
        }

        return 0;
    }
    catch (std::exception &e) {
        std::cerr << "Error occurred during file processing: " << e.what() << "\n";
        return -1;
    }
}

int main() {
    std::string filePath = "example.fasta";
    int expectedCount = 3;
    int result = validateFastaFile(filePath, expectedCount);
    if (result == 0) {
        std::cout << "FASTA file is valid.\n";
    } else {
        std::cout << "FASTA file validation failed.\n";
    }
    return 0;
}
