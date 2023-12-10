#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <header file>\n";
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input) {
        std::cerr << "Error: unable to open file " << argv[1] << "\n";
        return 1;
    }

    std::vector<std::string> includes;
    std::string line;
    while (std::getline(input, line)) {
        if (line.find("#include") != std::string::npos) {
            std::string include = line.substr(line.find('"') + 1, line.find('"', line.find('"') + 1) - line.find('"') - 1);
            includes.push_back(include);
        }
    }

    for (const auto& include : includes) {
        std::cout << include << "\n";
    }

    return 0;
}
