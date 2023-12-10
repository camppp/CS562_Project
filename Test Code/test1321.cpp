#include <fstream>
#include <string>

int countNamespaceOccurrences(const std::string& filePath, const std::string& targetNamespace) {
    std::ifstream file(filePath);
    std::string line;
    int count = 0;

    while (std::getline(file, line)) {
        size_t pos = line.find("namespace " + targetNamespace);
        if (pos != std::string::npos) {
            count++;
        }
    }

    return count;
}
