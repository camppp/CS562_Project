#include <vector>
#include <numeric>
#include <algorithm>

std::vector<int> convolution(std::vector<int> a, std::vector<int> b) {
    int n = a.size();
    std::vector<int> c(2*n-1, 0);
    for (int i = 0; i < 2*n-1; ++i) {
        for (int j = std::max(0, i-n+1); j <= std::min(i, n-1); ++j) {
            c[i] += a[j] * b[i-j];
        }
    }
    return c;
}