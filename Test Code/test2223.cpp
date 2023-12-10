#include <vector>
#include <algorithm>

class HitCollector {
public:
    // ... other member functions

    std::vector<std::pair<int, int>> getSortedHitSequence(int N) {
        // Implementation to retrieve and sort hits
    }
};

std::vector<int> extractAndSortHits(const HitCollector& hc, int N) {
    std::vector<std::pair<int, int>> hitSequence = hc.getSortedHitSequence(N);
    std::vector<int> hitScores;
    for (const auto& hit : hitSequence) {
        hitScores.push_back(hit.second);  // Extract hit scores
    }
    return hitScores;
}
