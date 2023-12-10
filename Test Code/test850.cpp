#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::regex starRegex(R"((\d+)-\d+)");
    std::smatch starMatch;
    if (std::regex_search(input, starMatch, starRegex)) {
        int starCount = std::stoi(starMatch[1]);
        std::cout << starCount << " ";

        std::string codeSnippet = input.substr(input.find('\n') + 1);
        int namespaceCount = 0;
        size_t pos = 0;
        while ((pos = codeSnippet.find("namespace", pos)) != std::string::npos) {
            namespaceCount++;
            pos += 9; // Move past the found "namespace" to search for the next occurrence
        }
        std::cout << namespaceCount << std::endl;
    }

    return 0;
}
