#include <iostream>
#include <sstream>
#include <unordered_set>

int countUniqueWords(std::stringstream& input) {
    std::unordered_set<std::string> uniqueWords;
    std::string word;
    
    while (input >> word) {
        // Remove punctuation from the word
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
        
        // Convert the word to lowercase
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        
        uniqueWords.insert(word);
    }
    
    return uniqueWords.size();
}
