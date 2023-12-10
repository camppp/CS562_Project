#include <stxxl/vector>
#include <stxxl/sorter>
#include <stxxl/algorithm>
#include <vector>

std::vector<int> parallelMultiwayMerge(const std::vector<std::vector<int>>& sortedSequences) {
    std::vector<int> result;

    // Create STXXL vectors for input and output
    stxxl::vector<int> stxxlInput;
    for (const auto& seq : sortedSequences) {
        stxxlInput.insert(stxxlInput.end(), seq.begin(), seq.end());
    }

    stxxl::vector<int> stxxlOutput;

    // Perform parallel multiway merge using STXXL
    stxxl::multiway_merge(stxxlInput.begin(), stxxlInput.end(), stxxlOutput.begin(), sortedSequences.size());

    // Copy the result from STXXL vector to standard vector
    result.reserve(stxxlOutput.size());
    for (const auto& val : stxxlOutput) {
        result.push_back(val);
    }

    return result;
}
