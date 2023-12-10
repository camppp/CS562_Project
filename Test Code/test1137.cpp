#include <iostream>
#include <string>
#include <cctype>

int countWordOccurrences(const std::string& text, const std::string& word) {
    int count = 0;
    std::string lowerText = text;
    std::string lowerWord = word;
    
    // Convert both text and word to lowercase
    for (char& c : lowerText) {
        c = std::tolower(c);
    }
    for (char& c : lowerWord) {
        c = std::tolower(c);
    }
    
    // Find whole word matches
    size_t pos = lowerText.find(lowerWord, 0);
    while (pos != std::string::npos) {
        if ((pos == 0 || !std::isalpha(lowerText[pos - 1])) && 
            (pos + lowerWord.length() == lowerText.length() || !std::isalpha(lowerText[pos + lowerWord.length()]))) {
            count++;
        }
        pos = lowerText.find(lowerWord, pos + 1);
    }
    
    return count;
}

int main() {
    std::string text = "The cat and the cattle are playing with a caterpillar";
    std::string word = "cat";
    std::cout << countWordOccurrences(text, word) << std::endl;  // Output: 2
    return 0;
}
