#include <vector>
#include <utility>

std::vector<int> extractAndSortHits(const HitCollector& hc, int N) {
    // Get the sorted hit sequence from the hit collector
    auto sortedHitSequence = hc.getSortedHitSequence(N);

    // Extract the hit scores from the sorted hit sequence
    std::vector<int> hitScores;
    for (const auto& hit : sortedHitSequence) {
        hitScores.push_back(hit.second);
    }

    // Sort the hit scores in descending order
    std::sort(hitScores.begin(), hitScores.end(), std::greater<int>());

    return hitScores;
}
