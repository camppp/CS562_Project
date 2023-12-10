#include <iostream>
#include <vector>

using namespace std;

vector<int> calculateTotalScore(const vector<int>& scores) {
    vector<int> totalScores(scores.size());

    for (int i = 0; i < scores.size(); i++) {
        int sum = 0;
        for (int j = 0; j < 3 && j < scores.size(); j++) {
            sum += scores[i + j];
        }
        totalScores[i] = sum;
    }

    return totalScores;
}

int main() {
    vector<int> scores = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    vector<int> totalScores = calculateTotalScore(scores);

    for (int i = 0; i < totalScores.size(); i++) {
        cout << "Player " << i + 1 << " total score: " << totalScores[i] << endl;
    }

    return 0;
}
