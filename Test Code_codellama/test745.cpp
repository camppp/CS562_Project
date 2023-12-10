#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Error: unable to open file " << argv[1] << "\n";
        return 1;
    }

    int count = 0;
    std::string line;
    while (std::getline(file, line)) {
        if (line.find("#endif") != std::string::npos) {
            count++;
        }
    }

    std::cout << "Number of #endif directives: " << count << "\n";

    return 0;
}
