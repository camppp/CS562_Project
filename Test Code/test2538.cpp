#include <fstream>
#include <string>
#include <regex>

int countWordOccurrences(const std::string& filePath, const std::string& targetWord) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        return -1;  // File open error
    }

    int count = 0;
    std::string line;
    bool inMultiLineComment = false;
    while (std::getline(file, line)) {
        std::string processedLine;
        for (size_t i = 0; i < line.size(); ++i) {
            if (line[i] == '"') {
                size_t nextQuote = line.find('"', i + 1);
                if (nextQuote != std::string::npos) {
                    processedLine += line.substr(i, nextQuote - i + 1);
                    i = nextQuote;
                }
            } else if (line[i] == '/' && i + 1 < line.size()) {
                if (line[i + 1] == '/') {
                    break;  // Ignore the rest of the line as it's a single-line comment
                } else if (line[i + 1] == '*') {
                    inMultiLineComment = true;
                    ++i;
                }
            } else if (inMultiLineComment && line[i] == '*' && i + 1 < line.size() && line[i + 1] == '/') {
                inMultiLineComment = false;
                ++i;
            } else if (!inMultiLineComment) {
                processedLine += line[i];
            }
        }

        std::regex wordRegex("\\b" + targetWord + "\\b");
        count += std::distance(std::sregex_iterator(processedLine.begin(), processedLine.end(), wordRegex),
                              std::sregex_iterator());
    }

    file.close();
    return count;
}
