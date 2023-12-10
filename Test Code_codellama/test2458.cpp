#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    // Get the path to the text file to be analyzed
    string filePath;
    cout << "Enter the path to the text file: ";
    cin >> filePath;

    // Get the number of top words to be displayed
    int n;
    cout << "Enter the number of top words to be displayed: ";
    cin >> n;

    // Open the text file
    ifstream file(filePath);
    if (!file) {
        cout << "Error: Could not open file " << filePath << endl;
        return 1;
    }

    // Read the text file and count the frequency of each word
    map<string, int> wordFrequencies;
    string word;
    while (file >> word) {
        // Convert the word to lowercase
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Increment the frequency of the word
        wordFrequencies[word]++;
    }

    // Sort the word frequencies in descending order
    vector<pair<string, int>> sortedWordFrequencies(wordFrequencies.begin(), wordFrequencies.end());
    sort(sortedWordFrequencies.begin(), sortedWordFrequencies.end(),
        [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second;
        });

    // Output the top N most frequently occurring words
    for (int i = 0; i < n; i++) {
        cout << sortedWordFrequencies[i].first << ": " << sortedWordFrequencies[i].second << endl;
    }

    return 0;
}
