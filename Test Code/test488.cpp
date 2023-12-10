#include <iostream>
#include <string>
#include <algorithm>

int countWordOccurrences(const std::string& text, const std::string& word) {
    std::string lowerText = text;
    std::string lowerWord = word;
    
    // Convert both the text and word to lowercase for case-insensitive matching
    std::transform(lowerText.begin(), lowerText.end(), lowerText.begin(), ::tolower);
    std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
    
    int count = 0;
    size_t pos = lowerText.find(lowerWord, 0);
    while (pos != std::string::npos) {
        count++;
        pos = lowerText.find(lowerWord, pos + lowerWord.length());
    }
    
    return count;
}

int main() {
    std::string text = "This is a sample text. This text contains the word 'this' multiple times. This is a simple example.";
    std::string word = "this";
    
    int occurrences = countWordOccurrences(text, word);
    std::cout << "Number of occurrences of the word '" << word << "': " << occurrences << std::endl;
    
    return 0;
}
