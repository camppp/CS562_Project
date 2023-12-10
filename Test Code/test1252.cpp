#include <fstream>
#include <sstream>
#include <algorithm>

int countWordOccurrences(const std::string& filename, const std::string& word) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        // Handle file open error
        return -1;
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    std::transform(content.begin(), content.end(), content.begin(), ::tolower);
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    std::istringstream iss(content);
    std::string token;
    int count = 0;
    while (iss >> token) {
        if (token == word) {
            count++;
        }
    }

    return count;
}
