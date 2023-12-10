#include <iostream>
#include <string>
#include <cctype>

bool isAlphanumeric(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_';
}

int countWordOccurrences(const std::string& text, const std::string& word) {
    int count = 0;
    std::string lowerText = text;
    std::string lowerWord = word;
    
    // Convert both text and word to lowercase for case-insensitive comparison
    for (char& c : lowerText) {
        c = std::tolower(c);
    }
    for (char& c : lowerWord) {
        c = std::tolower(c);
    }
    
    size_t pos = lowerText.find(lowerWord, 0);
    while (pos != std::string::npos) {
        // Check if the found word is a whole word
        if ((pos == 0 || !isAlphanumeric(lowerText[pos - 1])) && 
            (pos + lowerWord.length() == lowerText.length() || !isAlphanumeric(lowerText[pos + lowerWord.length()]))) {
            count++;
        }
        pos = lowerText.find(lowerWord, pos + 1);
    }
    
    return count;
}

int main() {
    std::string text = "The cat and the dog are playing in the cathedral";
    std::string word = "the";
    std::cout << countWordOccurrences(text, word) << std::endl;  // Output: 2
    return 0;
}
