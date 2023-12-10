#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Score {
    int score;
};

struct ScoreComparator {
    bool operator()(const Score& lhs, const Score& rhs) {
        return lhs.score < rhs.score;
    }
};

struct ScoreAverage {
    int sum;
    int count;

    ScoreAverage(int sum, int count) : sum(sum), count(count) {}

    float getAverage() {
        return (float)sum / count;
    }
};

struct ScoreStats {
    int highest;
    int lowest;
    float average;

    ScoreStats(int highest, int lowest, float average) : highest(highest), lowest(lowest), average(average) {}
};

ScoreStats calculateScores(const vector<Score>& scores) {
    int highest = scores[0].score;
    int lowest = scores[0].score;
    int sum = 0;
    int count = 0;

    for (const Score& score : scores) {
        sum += score.score;
        count++;

        if (score.score > highest) {
            highest = score.score;
        }

        if (score.score < lowest) {
            lowest = score.score;
        }
    }

    ScoreAverage average = ScoreAverage(sum, count);
    return ScoreStats(highest, lowest, average.getAverage());
}

int main() {
    vector<Score> scores = {
        {85},
        {90},
        {92},
        {88},
        {78},
        {95},
        {87},
        {80}
    };

    ScoreStats stats = calculateScores(scores);
    cout << "Average score: " << stats.average << endl;
    cout << "Highest score: " << stats.highest << endl;
    cout << "Lowest score: " << stats.lowest << endl;

    return 0;
}
