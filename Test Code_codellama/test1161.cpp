#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main() {
    std::string text = "The quick brown fox jumps over the lazy dog. The dog barks, and the fox jumps.";

    // Split the text into individual words
    std::vector<std::string> words;
    std::stringstream ss(text);
    std::string word;
    while (ss >> word) {
        words.push_back(word);
    }

    // Create a map to store the frequency of each word
    std::map<std::string, int> word_freq;

    // Iterate over the words and increment the frequency of each word
    for (const auto& word : words) {
        if (word_freq.find(word) != word_freq.end()) {
            word_freq[word]++;
        } else {
            word_freq[word] = 1;
        }
    }

    // Sort the map by frequency in descending order
    std::vector<std::pair<std::string, int>> sorted_word_freq(word_freq.begin(), word_freq.end());
    std::sort(sorted_word_freq.begin(), sorted_word_freq.end(),
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                  return a.second > b.second;
              });

    // Print the sorted map
    for (const auto& [word, freq] : sorted_word_freq) {
        std::cout << word << ": " << freq << std::endl;
    }

    return 0;
}
