#include <iostream>
#include <string>
#include <unordered_set>

int countUniqueHeaderFiles(const std::string& sourceCode) {
    std::unordered_set<std::string> includedHeaders;
    size_t pos = 0;
    while ((pos = sourceCode.find("#include", pos)) != std::string::npos) {
        size_t start = sourceCode.find_first_of("<\"", pos);
        size_t end = sourceCode.find_first_of(">\"", start + 1);
        if (start != std::string::npos && end != std::string::npos) {
            std::string header = sourceCode.substr(start + 1, end - start - 1);
            includedHeaders.insert(header);
        }
        pos = end;
    }
    return includedHeaders.size();
}
