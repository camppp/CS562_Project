#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<pair<string, int>> scores;

    // Read in the scores
    string name;
    int score;
    while (cin >> name >> score) {
        scores.push_back(make_pair(name, score));
    }

    // Sort the scores in descending order
    sort(scores.begin(), scores.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });

    // Output the scores in a formatted table
    cout << "Student\tScore\n";
    for (const auto& score : scores) {
        cout << left << setw(15) << score.first << setw(5) << score.second << '\n';
    }

    return 0;
}
