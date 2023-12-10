#include <vector>
#include <algorithm>

int maxCookies(std::vector<int>& g, std::vector<int>& s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    
    int result = 0;
    int i = 0, j = 0;
    while (i < g.size() && j < s.size()) {
        if (s[j] >= g[i]) {
            result++;
            i++;
        }
        j++;
    }
    return result;
}

int main() {
    // Test the maxCookies function
    std::vector<int> greedFactors = {1, 2, 3};
    std::vector<int> cookieSizes = {1, 1};
    int maxNumCookies = maxCookies(greedFactors, cookieSizes);
    // Output the result
    return 0;
}
