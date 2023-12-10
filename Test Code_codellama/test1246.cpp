#include <iostream>
#include <vector>

long long maxSubarraySum(int n, long long arr[]) {
    long long maxSum = 0;
    long long currentSum = 0;

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    return maxSum;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    long long result = maxSubarraySum(n, arr);
    std::cout << result << std::endl;

    return 0;
}
