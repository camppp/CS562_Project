#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

int calculateAverage(std::vector<int> scores) {
    if (scores.size() <= 2) {
        return 0;  // Handle edge case where there are less than 2 scores
    }
    // Sort the scores in ascending order
    std::sort(scores.begin(), scores.end());
    // Calculate the sum of scores excluding the first and last elements
    int sum = std::accumulate(scores.begin() + 1, scores.end() - 1, 0);
    // Calculate the average and round it to the nearest integer
    int average = std::round(static_cast<double>(sum) / (scores.size() - 2));
    return average;
}
