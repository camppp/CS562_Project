#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {
    // Open the file
    std::ifstream file("sample.txt");

    // Read the contents of the file
    std::string contents((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());

    // Prompt the user to input the words to search for
    std::cout << "Enter the words to search for: ";
    std::string search_words;
    std::getline(std::cin, search_words);

    // Split the search words into a vector
    std::vector<std::string> search_words_vector;
    std::stringstream ss(search_words);
    std::string word;
    while (ss >> word) {
        search_words_vector.push_back(word);
    }

    // Create a map to store the counts of each word
    std::map<std::string, int> word_counts;

    // Iterate through the contents of the file and count the occurrences of each word
    for (const auto& word : search_words_vector) {
        // Convert the word to lowercase to make it case-insensitive
        std::string lowercase_word = word;
        std::transform(lowercase_word.begin(), lowercase_word.end(), lowercase_word.begin(), ::tolower);

        // Increment the count of the word in the map
        word_counts[lowercase_word]++;
    }

    // Output the counts of each word
    for (const auto& word : word_counts) {
        std::cout << "Word '" << word.first << "' occurs " << word.second << " times." << std::endl;
    }

    return 0;
}
