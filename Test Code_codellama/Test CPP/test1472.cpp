#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

double calculateAverageFromCSV(const std::string& filePath, const std::string& columnName) {
    std::ifstream file(filePath);
    if (!file) {
        std::cerr << "Error: unable to open file " << filePath << std::endl;
        return 0;
    }

    // Read the header row
    std::string header;
    std::getline(file, header);

    // Find the index of the specified column
    int columnIndex = -1;
    std::stringstream headerStream(header);
    std::string column;
    while (std::getline(headerStream, column, ',')) {
        if (column == columnName) {
            columnIndex = headerStream.tellg();
            break;
        }
    }

    // Check if the specified column exists
    if (columnIndex == -1) {
        std::cerr << "Error: column " << columnName << " does not exist in the CSV file" << std::endl;
        return 0;
    }

    // Read the data rows
    std::vector<double> values;
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        std::string cell;
        while (std::getline(lineStream, cell, ',')) {
            if (columnIndex == 0) {
                // Skip the first column (name)
                continue;
            }
            double value = std::stod(cell);
            values.push_back(value);
        }
    }

    // Calculate the average
    double average = 0;
    for (double value : values) {
        average += value;
    }
    average /= values.size();

    return average;
}
