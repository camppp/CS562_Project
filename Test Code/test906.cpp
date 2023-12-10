Score calculateScores(const OnsetTimes& onsetTimes, const Thresholds& thresholds, const ScoreTable& scoreTable) {
    Score scores;
    for (int i = 0; i < onsetTimes.size(); i++) {
        double onsetTime = onsetTimes[i];
        int thresholdIndex = 0;
        while (thresholdIndex < thresholds.size() && onsetTime >= thresholds[thresholdIndex]) {
            thresholdIndex++;
        }
        if (thresholdIndex == 0) {
            scores.push_back(scoreTable[0][0]);
        } else if (thresholdIndex == 1) {
            scores.push_back(scoreTable[1][0]);
        } else if (thresholdIndex == 2) {
            scores.push_back(scoreTable[2][0]);
        }
    }
    return scores;
}
