#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class CsvParser {
public:
    CsvParser(const char* filename, char delimiter, bool skip_empty_lines) {
        this->filename = filename;
        this->delimiter = delimiter;
        this->skip_empty_lines = skip_empty_lines;
    }

    std::vector<std::vector<std::string>> parseFile() {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("cannot open file");
        }

        std::vector<std::vector<std::string>> data;
        std::string line;
        while (std::getline(file, line)) {
            if (skip_empty_lines && line.empty()) {
                continue;
            }

            std::vector<std::string> row;
            std::string cell;
            std::stringstream ss(line);
            while (std::getline(ss, cell, delimiter)) {
                row.push_back(cell);
            }
            data.push_back(row);
        }

        return data;
    }

private:
    const char* filename;
    char delimiter;
    bool skip_empty_lines;
};

int main() {
    CsvParser parser("example.csv", ',', true);
    try {
        std::vector<std::vector<std::string>> data = parser.parseFile();
        for (const auto& row : data) {
            for (const auto& cell : row) {
                std::cout << cell << " ";
            }
            std::cout << std::endl;
        }
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
