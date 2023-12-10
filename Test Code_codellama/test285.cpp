#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> countWordsInComments(const string& code) {
    vector<int> wordCounts;
    string comment;
    int wordCount = 0;

    // Iterate through the lines of the code
    for (int i = 0; i < code.size(); i++) {
        // Check if the current line is a comment
        if (code[i] == '/' && code[i + 1] == '/') {
            // Extract the comment text
            comment = code.substr(i + 2);

            // Count the number of words in the comment
            wordCount = 0;
            for (int j = 0; j < comment.size(); j++) {
                if (comment[j] != ' ') {
                    wordCount++;
                }
            }

            // Add the word count to the vector
            wordCounts.push_back(wordCount);
        }
    }

    return wordCounts;
}

int main() {
    string code = "// The .NET Foundation licenses this file to you under the MIT license. // See the LICENSE file in the project root for more information.";
    vector<int> wordCounts = countWordsInComments(code);

    // Print the word counts for each comment
    for (int i = 0; i < wordCounts.size(); i++) {
        cout << "Comment " << i + 1 << ": " << wordCounts[i] << " words" << endl;
    }

    return 0;
}
