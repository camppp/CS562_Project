#include <vector>
#include <array>
#include <algorithm>

using namespace std;

using OnsetTimes = vector<double>;
using Thresholds = array<int, 3>;
using ScoreElem = array<double, 5>;
using Score = vector<ScoreElem>;

Score calculateScores(const OnsetTimes& onsetTimes, const Thresholds& thresholds, const Score& scoreTable) {
    Score result;

    for (const auto& onsetTime : onsetTimes) {
        double score;
        if (onsetTime < thresholds[0]) {
            score = scoreTable[0][0];
        } else if (onsetTime < thresholds[1]) {
            score = scoreTable[0][1];
        } else {
            score = scoreTable[0][2];
        }
        result.push_back({onsetTime, score});
    }

    sort(result.begin(), result.end(), [](const ScoreElem& a, const ScoreElem& b) {
        return a[0] < b[0];
    });

    return result;
}
