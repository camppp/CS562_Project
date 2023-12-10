#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int numStudents;
    cin >> numStudents;

    vector<string> studentNames;
    vector<vector<int>> studentScores;

    for (int i = 0; i < numStudents; i++) {
        string name;
        cin >> name;
        studentNames.push_back(name);

        vector<int> scores;
        int numScores;
        cin >> numScores;
        for (int j = 0; j < numScores; j++) {
            int score;
            cin >> score;
            scores.push_back(score);
        }
        studentScores.push_back(scores);
    }

    for (int i = 0; i < numStudents; i++) {
        int sum = 0;
        for (int j = 0; j < studentScores[i].size(); j++) {
            sum += studentScores[i][j];
        }
        double average = sum / (double)studentScores[i].size();
        cout << studentNames[i] << " " << fixed << setprecision(2) << average << endl;
    }

    return 0;
}
