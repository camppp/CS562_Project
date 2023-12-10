#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

std::string extractMetadata(const std::string& filename) {
    std::ifstream variantFile(filename);
    std::string metadata;

    if (!variantFile.is_open()) {
        return "Error: Unable to open file";
    }

    std::string line;
    while (std::getline(variantFile, line)) {
        if (line.find("##") == 0) {
            line = line.substr(2);  // Remove "##" from the beginning
            size_t pos = line.find('=');
            if (pos != std::string::npos) {
                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos + 1);
                metadata += key + ": " + value + "\n";
            }
        } else if (line.find("#CHROM") == 0) {
            break;  // End of header section
        }
    }

    variantFile.close();
    return metadata;
}

int main() {
    std::string filename = "genetic_variants.vcf";
    std::string extractedMetadata = extractMetadata(filename);
    std::cout << extractedMetadata << std::endl;
    return 0;
}
