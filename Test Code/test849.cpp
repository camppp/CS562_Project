#include "reader.h"
#include "writer.h"
#include <algorithm>
#include <iostream>

int main() {
    // Step 1: Read data from input file
    std::vector<int> inputData = readData("input.txt");

    // Step 2: Modify the data
    std::sort(inputData.begin(), inputData.end());  // Sort the data
    inputData.erase(std::unique(inputData.begin(), inputData.end()), inputData.end());  // Remove duplicates

    // Step 3: Write modified data to output file
    writeData(inputData, "output.txt");

    return 0;
}
