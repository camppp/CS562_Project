#include <iostream>
#include <string>
#include <cctype>

bool isWordCharacter(char c) {
    return std::isalnum(c) || c == '_';
}

int countWordOccurrences(const std::string& text, const std::string& word) {
    int count = 0;
    std::string lowerText = text;
    std::string lowerWord = word;
    std::transform(lowerText.begin(), lowerText.end(), lowerText.begin(), ::tolower);
    std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

    size_t pos = lowerText.find(lowerWord, 0);
    while (pos != std::string::npos) {
        if ((pos == 0 || !isWordCharacter(lowerText[pos - 1])) &&
            (pos + lowerWord.length() == lowerText.length() || !isWordCharacter(lowerText[pos + lowerWord.length()]))) {
            count++;
        }
        pos = lowerText.find(lowerWord, pos + 1);
    }
    return count;
}

int main() {
    std::string text = "The cat and the dog are playing in the garden. The cat is happy.";
    std::string word = "the";
    std::cout << "Occurrences of '" << word << "': " << countWordOccurrences(text, word) << std::endl;
    return 0;
}
