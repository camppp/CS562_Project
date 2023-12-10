#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <source_file_path>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file" << std::endl;
        return 1;
    }

    std::string line;
    std::regex copyrightRegex("// Copyright (C) (\\d{4}) (.+)");
    std::smatch match;

    while (std::getline(file, line)) {
        if (std::regex_search(line, match, copyrightRegex)) {
            std::cout << "Copyright Year: " << match[1] << std::endl;
            std::cout << "Author: " << match[2] << std::endl;
            return 0;
        }
    }

    std::cerr << "Error: Copyright notice not found in the source file" << std::endl;
    return 1;
}
