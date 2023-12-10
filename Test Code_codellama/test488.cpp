#include <string>
#include <algorithm>

namespace sim {

int countWordOccurrences(const std::string& text, const std::string& word) {
    // Convert the input text and word to lowercase
    std::string lowerText = text;
    std::string lowerWord = word;
    std::transform(lowerText.begin(), lowerText.end(), lowerText.begin(), ::tolower);
    std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

    // Count the number of occurrences of the word in the text
    int count = 0;
    size_t pos = 0;
    while ((pos = lowerText.find(lowerWord, pos)) != std::string::npos) {
        ++count;
        pos += lowerWord.length();
    }

    return count;
}

} // namespace sim
