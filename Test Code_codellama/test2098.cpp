#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int countOccurrences(const string& filePath, const string& targetWord) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filePath << endl;
        return -1;
    }

    string line;
    vector<string> words;
    int count = 0;

    while (getline(file, line)) {
        words = split(line, ' ');
        for (const string& word : words) {
            if (word == targetWord) {
                count++;
            }
        }
    }

    file.close();
    return count;
}

int main() {
    string filePath = "sample.txt";
    string targetWord = "sample";
    int count = countOccurrences(filePath, targetWord);
    cout << "The word " << targetWord << " appears " << count << " times in the file " << filePath << endl;
    return 0;
}
