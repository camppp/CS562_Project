#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main() {
    std::string text;
    std::getline(std::cin, text);

    std::map<std::string, int> word_freq;

    // Tokenize the input text
    std::stringstream ss(text);
    std::string word;
    while (ss >> word) {
        // Ignore punctuation marks
        if (word.find_first_not_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos) {
            // Convert to lowercase
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            // Increment the frequency of the word
            word_freq[word]++;
        }
    }

    // Sort the map by frequency
    std::vector<std::pair<std::string, int>> sorted_word_freq(word_freq.begin(), word_freq.end());
    std::sort(sorted_word_freq.begin(), sorted_word_freq.end(),
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                  return a.second > b.second;
              });

    // Print the sorted map
    for (const auto& p : sorted_word_freq) {
        std::cout << p.first << ": " << p.second << std::endl;
    }

    return 0;
}
