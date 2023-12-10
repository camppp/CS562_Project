#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

int main() {
    // Open the input file
    std::ifstream input_file("input.txt");

    // Create a map to store the word frequencies
    std::map<std::string, int> word_freq;

    // Read the input file and update the word frequencies
    std::string word;
    while (input_file >> word) {
        // Ignore punctuation and convert to lowercase
        word = word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
        word = word.to_lower();

        // Increment the frequency of the word
        ++word_freq[word];
    }

    // Output the top N most frequently occurring words
    int n = 5; // Replace with user-specified integer
    for (const auto& [word, freq] : word_freq) {
        if (--n <= 0) {
            break;
        }
        std::cout << word << ": " << freq << std::endl;
    }

    return 0;
}
