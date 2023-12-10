#include <stxxl/vector>
#include <stxxl/sort>

std::vector<int> parallelMultiwayMerge(const std::vector<std::vector<int>>& sortedSequences) {
    // Create a vector of STXXL vectors to hold the sorted sequences
    std::vector<stxxl::vector<int>> stxxlSequences;
    for (const auto& sequence : sortedSequences) {
        stxxlSequences.push_back(stxxl::vector<int>(sequence.begin(), sequence.end()));
    }

    // Perform a parallel multiway merge on the STXXL vectors
    stxxl::sort(stxxlSequences.begin(), stxxlSequences.end(), stxxl::less<int>());

    // Create a vector to hold the merged sequence
    std::vector<int> mergedSequence;

    // Iterate over the STXXL vectors and append their elements to the merged sequence
    for (const auto& stxxlSequence : stxxlSequences) {
        mergedSequence.insert(mergedSequence.end(), stxxlSequence.begin(), stxxlSequence.end());
    }

    return mergedSequence;
}
