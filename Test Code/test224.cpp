#include <vector>
#include <algorithm>

std::vector<std::vector<int>> generatePermutations(const std::vector<int>& elements) {
    std::vector<std::vector<int>> result;
    std::vector<int> currentPermutation = elements;

    do {
        result.push_back(currentPermutation);
    } while (std::next_permutation(currentPermutation.begin(), currentPermutation.end()));

    return result;
}
