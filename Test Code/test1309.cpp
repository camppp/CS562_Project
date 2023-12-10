#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void processSpeciesInfo(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        std::cout << "----------------------------------------\n";
        std::cout << "  Species Information\n";
        std::cout << "----------------------------------------\n";
        std::cout << std::left << std::setw(17) << "Species Name" << "| " << std::setw(15) << "Common Name" << "| " << "Family\n";
        std::cout << "----------------------------------------\n";

        std::string speciesName, commonName, family;
        while (std::getline(inputFile, speciesName, ',') &&
               std::getline(inputFile, commonName, ',') &&
               std::getline(inputFile, family)) {
            std::cout << std::left << std::setw(17) << speciesName << "| " << std::setw(15) << commonName << "| " << family << "\n";
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Unable to open file " << fileName << std::endl;
    }
}

int main() {
    processSpeciesInfo("species_info.txt");
    return 0;
}
