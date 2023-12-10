#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    // Get the path to the input file
    string inputFilePath;
    cout << "Enter the path to the input file: ";
    cin >> inputFilePath;

    // Get the value of N
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    // Open the input file
    ifstream inputFile(inputFilePath);

    // Create a map to store the word counts
    map<string, int> wordCounts;

    // Read the input file line by line
    string line;
    while (getline(inputFile, line)) {
        // Tokenize the line into words
        stringstream ss(line);
        string word;
        while (ss >> word) {
            // Ignore common English stop words
            if (word.length() > 0 && !isStopWord(word)) {
                // Increment the count for the word
                wordCounts[word]++;
            }
        }
    }

    // Sort the map by value (count) in descending order
    sort(wordCounts.begin(), wordCounts.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             return a.second > b.second;
         });

    // Output the top N most frequently occurring words and their counts
    for (int i = 0; i < n && i < wordCounts.size(); i++) {
        cout << wordCounts[i].first << ": " << wordCounts[i].second << endl;
    }

    return 0;
}

// Check if a word is a common English stop word
bool isStopWord(const string& word) {
    static const vector<string> stopWords = {
        "the", "and", "of", "to", "in", "a", "is", "it", "that", "as", "was", "for", "on", "with", "by", "at", "but", "from", "or", "an", "are", "not", "this", "be", "which", "have", "has", "had", "one", "we", "all", "their", "there", "when", "who", "where", "why", "what", "how", "so", "if", "my", "your", "his", "her", "its", "our", "their", "some", "more", "most", "many", "much", "few", "little", "other", "only", "own", "same", "such", "no", "nor", "not", "too", "very", "s", "t", "can", "will", "just", "don", "should", "now"
    };
    return find(stopWords.begin(), stopWords.end(), word) != stopWords.end();
}
