#include <iostream>
#include <fstream>
#include <string>

void processSpeciesInfo(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: unable to open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Split the line into its constituent parts
        std::string speciesName, commonName, family;
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            speciesName = line.substr(0, commaPos);
            commonName = line.substr(commaPos + 1);
            commaPos = commonName.find(',');
            if (commaPos != std::string::npos) {
                family = commonName.substr(commaPos + 1);
            }
        }

        // Display the information in the desired format
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "  Species Information" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Species Name      | Common Name    | Family" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << speciesName << " | " << commonName << " | " << family << std::endl;
    }
}
