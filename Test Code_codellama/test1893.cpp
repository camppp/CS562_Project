#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

int main() {
    // Open the input file
    std::ifstream input("input.txt");

    // Create a map to store the word counts
    std::map<std::string, int> word_counts;

    // Read the input file and tokenize the words
    std::string word;
    while (input >> word) {
        // Convert the word to lowercase
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Ignore punctuation and consider "dog" and "dog." as the same word
        if (word.find_first_not_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos) {
            word = "dog";
        }

        // Increment the count for the current word
        word_counts[word]++;
    }

    // Output the word counts in descending order of frequency
    for (const auto& word_count : word_counts) {
        std::cout << word_count.first << ": " << word_count.second << std::endl;
    }

    return 0;
}
