#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Open the input text file
    ifstream input_file("license.txt");

    // Open the input phrases file
    ifstream phrases_file("phrases.txt");

    // Create a vector to store the phrases
    vector<string> phrases;

    // Read the phrases from the phrases file
    while (phrases_file >> phrase) {
        phrases.push_back(phrase);
    }

    // Create a map to store the counts of each phrase
    map<string, int> counts;

    // Read the input text file and count the occurrences of each phrase
    while (input_file >> line) {
        for (string phrase : phrases) {
            if (line.find(phrase) != string::npos) {
                counts[phrase]++;
            }
        }
    }

    // Output the counts of each phrase
    for (auto count : counts) {
        cout << count.first << ": " << count.second << endl;
    }

    return 0;
}
