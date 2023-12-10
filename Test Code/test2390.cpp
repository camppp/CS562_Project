#include <vector>
#include <utility>

void calculateWeights(std::vector<std::pair<int, int>>& merge_candidates, std::vector<double>& scores) {
    scores.reserve(merge_candidates.size());

    for (const auto& merge_candidate : merge_candidates) {
        int first_index = merge_candidate.first;
        int second_index = merge_candidate.second;

        // Calculate weight for merging transition systems with indices first_index and second_index
        // ... (implement weight calculation logic here)

        double weight = calculateWeightForMerge(first_index, second_index); // Replace with actual weight calculation

        scores.push_back(weight);
    }
}
