#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    // Remove punctuation and convert to lowercase
    for (int i = 0; i < text.length(); i++) {
        if (ispunct(text[i]) || isspace(text[i])) {
            text[i] = ' ';
        } else {
            text[i] = tolower(text[i]);
        }
    }

    // Split text into words
    vector<string> words;
    stringstream ss(text);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }

    // Count frequency of each word
    unordered_map<string, int> word_freq;
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        if (word_freq.find(word) == word_freq.end()) {
            word_freq[word] = 1;
        } else {
            word_freq[word]++;
        }
    }

    // Print frequency of each word
    for (auto it = word_freq.begin(); it != word_freq.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}
