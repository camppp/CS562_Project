#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

int main() {
    // Open the input file
    std::ifstream input("input.txt");

    // Create a map to store the word frequencies
    std::map<std::string, int> word_freq;

    // Read the input file line by line
    std::string line;
    while (std::getline(input, line)) {
        // Tokenize the line into words
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            // Convert the word to lowercase
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);

            // Increment the frequency of the word
            word_freq[word]++;
        }
    }

    // Sort the map by frequency in descending order
    std::sort(word_freq.begin(), word_freq.end(),
              [](const std::pair<std::string, int>& a,
                 const std::pair<std::string, int>& b) {
                  return a.second > b.second;
              });

    // Output the word frequencies
    for (const auto& word_freq : word_freq) {
        std::cout << word_freq.first << ": " << word_freq.second << std::endl;
    }

    return 0;
}
