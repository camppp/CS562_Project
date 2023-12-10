#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string extractMetadata(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::stringstream ss;

    // Read the header section of the file
    while (std::getline(file, line)) {
        if (line.substr(0, 2) == "##") {
            // Extract the metadata key and value
            std::string key = line.substr(2, line.find("=") - 2);
            std::string value = line.substr(line.find("=") + 1);

            // Add the metadata to the stringstream
            ss << key << ": " << value << std::endl;
        }
    }

    // Return the formatted metadata string
    return ss.str();
}
