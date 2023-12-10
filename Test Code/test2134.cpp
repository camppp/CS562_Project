#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cassert>

class CsvParser {
public:
    std::vector<std::vector<std::string>> parseFile(const std::string& filename, char delimiter, bool skipEmptyLines) {
        std::vector<std::vector<std::string>> parsedData;
        std::ifstream file(filename);
        
        if (!file.is_open()) {
            throw "cannot open file";
        }

        std::string line;
        while (std::getline(file, line)) {
            if (skipEmptyLines && line.empty()) {
                continue;
            }
            std::vector<std::string> row;
            std::stringstream ss(line);
            std::string cell;
            while (std::getline(ss, cell, delimiter)) {
                row.push_back(cell);
            }
            parsedData.push_back(row);
        }
        file.close();
        return parsedData;
    }
};

int main() {
    CsvParser csvParser;
    try {
        csvParser.parseFile("not-existing-file.csv", ',', true);
    } catch (const char* ex) {
        assert(strcmp(ex, "cannot open file") == 0);
        std::cout << "Exception handling for non-existing file test passed." << std::endl;
    }
    return 0;
}
