#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::ifstream inputFile("example_header.h");
    std::string line;
    std::vector<std::string> includedFiles;

    while (std::getline(inputFile, line)) {
        std::smatch match;
        if (std::regex_search(line, match, std::regex("#include\\s+([\"<])([^\">]+)([\">])"))) {
            includedFiles.push_back(match[2]);
        }
    }

    std::copy(includedFiles.begin(), includedFiles.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

    return 0;
}
