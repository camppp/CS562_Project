#include <iostream>
#include <fstream>

void load() {
    std::ifstream file("data.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Error: Could not open file" << std::endl;
    }
}

int main() {
    load();
    return 0;
}
