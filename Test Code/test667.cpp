int maxLongestCommonPrefix(const std::vector<int>& input) {
    int maxLCP = 0;
    for (size_t i = 1; i < input.size(); ++i) {
        int commonPrefix = 0;
        int minLength = std::min(input[i - 1], input[i]);
        while (commonPrefix < 32 && ((input[i - 1] >> commonPrefix) == (input[i] >> commonPrefix))) {
            ++commonPrefix;
        }
        maxLCP = std::max(maxLCP, commonPrefix);
    }
    return maxLCP;
}
