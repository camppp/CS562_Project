#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> splitString(const std::string& s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}

int main() {
    std::string input = "apple,orange,banana,grape";
    char delimiter = ',';
    std::vector<std::string> tokens = splitString(input, delimiter);
    for (const auto& token : tokens) {
        std::cout << token << std::endl;
    }
    return 0;
}
