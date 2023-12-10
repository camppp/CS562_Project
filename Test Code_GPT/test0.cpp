#include <iostream>
#include <vector>

std::vector<int> convolution(const std::vector<int>& a, const std::vector<int>& b) {
    int n = a.size();
    std::vector<int> result(2 * n - 1, 0);

    for (int i = 0; i < 2 * n - 1; ++i) {
        for (int j = std::max(0, i - n + 1); j <= std::min(i, n - 1); ++j) {
            result[i] += a[j] * b[i - j];
        }
    }

    return result;
}

int main() {
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {4, 5, 6};

    std::vector<int> result = convolution(a, b);

    std::cout << "Result: [";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
