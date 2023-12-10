#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {
    // Prompt the user to input the file path of the text file to be analyzed
    std::string file_path;
    std::cout << "Enter the file path of the text file to be analyzed: ";
    std::cin >> file_path;

    // Open the file and read its contents
    std::ifstream file(file_path);
    std::string contents((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());

    // Prompt the user to input a list of words to search for within the file
    std::string word_list;
    std::cout << "Enter a list of words to search for (separated by spaces): ";
    std::cin >> word_list;

    // Split the word list into individual words
    std::vector<std::string> words;
    std::stringstream ss(word_list);
    std::string word;
    while (ss >> word) {
        words.push_back(word);
    }

    // Count the occurrences of each word in the list within the file
    std::map<std::string, int> counts;
    for (const auto& word : words) {
        int count = 0;
        for (const auto& c : contents) {
            if (c == word[0] || c == word[0] + 'a' - 'A') {
                count++;
            }
        }
        counts[word] = count;
    }

    // Output the count of each word in the list that appears in the text file
    for (const auto& [word, count] : counts) {
        std::cout << word << ": " << count << std::endl;
    }

    return 0;
}
