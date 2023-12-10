#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "reader.h"
#include "writer.h"

int main() {
    // Read data from input.txt
    std::vector<int> data = readData("input.txt");

    // Remove duplicates and sort the remaining integers
    std::sort(data.begin(), data.end());
    data.erase(std::unique(data.begin(), data.end()), data.end());

    // Write modified data to output.txt
    writeData(data, "output.txt");

    return 0;
}
