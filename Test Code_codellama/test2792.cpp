#include <string>
#include <algorithm>

int countWordOccurrences(const std::string& text, const std::string& word) {
    int count = 0;
    std::string::size_type start = 0;
    while ((start = text.find(word, start)) != std::string::npos) {
        ++count;
        start += word.length();
    }
    return count;
}
