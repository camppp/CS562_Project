#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <regex>

int main() {
    std::ifstream file("input_header_file.hpp");
    std::string line;
    std::map<std::string, int> namespaceCount;

    while (std::getline(file, line)) {
        std::smatch match;
        std::regex nsRegex("namespace\\s+(\\w+)\\s*\\{");
        if (std::regex_search(line, match, nsRegex)) {
            std::string namespaceName = match[1].str();
            namespaceCount[namespaceName]++;
        }
    }

    for (const auto& pair : namespaceCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
