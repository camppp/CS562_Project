#include <iostream>
#include <algorithm>

int maxTrappedRainwater(int n, int buff[]) {
    int max_water = 0;
    for (int i = 1; i < n - 1; i++) {
        int left = 0, right = 0;
        for (int j = i - 1; j >= 0; j--) {
            left = std::max(left, buff[j]);
        }
        for (int j = i + 1; j < n; j++) {
            right = std::max(right, buff[j]);
        }
        max_water = std::max(max_water, left < right ? (right - left) : 0);
    }
    return max_water;
}

int main() {
    int n;
    std::cin >> n;
    int buff[n];
    for (int i = 0; i < n; i++) {
        std::cin >> buff[i];
    }
    std::cout << maxTrappedRainwater(n, buff) << std::endl;
    return 0;
}
