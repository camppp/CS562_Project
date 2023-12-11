#include <iostream>
#include <vector>
#include <string>

int maxLongestCommonPrefix(const std::vector<int>& input) {
    int max_lcp = 0;
    for (int i = 0; i < input.size() - 1; i++) {
        for (int j = i + 1; j < input.size(); j++) {
            int lcp = 0;
            while (lcp < input[i].size() && lcp < input[j].size() && input[i][lcp] == input[j][lcp]) {
                lcp++;
            }
            max_lcp = std::max(max_lcp, lcp);
        }
    }
    return max_lcp;
}

int main() {
    std::vector<int> input = {123, 12345, 1234, 1234567};
    std::cout << "Max LCP: " << maxLongestCommonPrefix(input) << std::endl;
    return 0;
}
