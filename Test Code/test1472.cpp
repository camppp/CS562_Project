#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <unordered_map>

double calculateAverageFromCSV(const std::string& filePath, const std::string& columnName) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << std::endl;
        return 0;
    }

    std::string line, cell;
    std::getline(file, line);  // Read the header line
    std::istringstream headerStream(line);
    std::vector<std::string> headers;
    while (std::getline(headerStream, cell, ',')) {
        headers.push_back(cell);
    }

    int columnIndex = -1;
    for (size_t i = 0; i < headers.size(); ++i) {
        if (headers[i] == columnName) {
            columnIndex = static_cast<int>(i);
            break;
        }
    }

    if (columnIndex == -1) {
        std::cerr << "Error: Column " << columnName << " not found in the CSV file" << std::endl;
        return 0;
    }

    double sum = 0.0;
    int count = 0;
    while (std::getline(file, line)) {
        std::istringstream lineStream(line);
        std::vector<std::string> values;
        while (std::getline(lineStream, cell, ',')) {
            values.push_back(cell);
        }
        if (columnIndex < values.size()) {
            try {
                sum += std::stod(values[columnIndex]);
                count++;
            } catch (const std::invalid_argument&) {
                std::cerr << "Error: Non-numeric value found in column " << columnName << std::endl;
                return 0;
            }
        } else {
            std::cerr << "Error: Inconsistent column count in the CSV file" << std::endl;
            return 0;
        }
    }

    file.close();

    if (count == 0) {
        std::cerr << "Error: No valid values found in column " << columnName << std::endl;
        return 0;
    }

    return sum / count;
}
