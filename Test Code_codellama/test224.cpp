std::vector<std::vector<int>> generatePermutations(const std::vector<int>& elements) {
    std::vector<std::vector<int>> permutations;
    generatePermutations(elements, permutations);
    return permutations;
}

void generatePermutations(const std::vector<int>& elements, std::vector<std::vector<int>>& permutations) {
    if (elements.empty()) {
        return;
    }

    for (int i = 0; i < elements.size(); i++) {
        std::vector<int> permutation(elements.begin(), elements.end());
        std::swap(permutation[i], permutation[i + 1]);
        permutations.push_back(permutation);
        generatePermutations(elements, permutations);
    }
}
