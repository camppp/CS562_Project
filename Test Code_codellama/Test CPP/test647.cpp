#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> count_unique_words(const string& input_string) {
    unordered_map<string, int> word_counts;

    // Split the input string into individual words
    vector<string> words = split(input_string, " ");

    // Iterate over each word and increment the count for that word
    for (const string& word : words) {
        word_counts[word]++;
    }

    return word_counts;
}

int main() {
    string input_string = "The cat and the hat.";
    unordered_map<string, int> word_counts = count_unique_words(input_string);

    for (const auto& word_count : word_counts) {
        cout << word_count.first << ": " << word_count.second << endl;
    }

    return 0;
}
