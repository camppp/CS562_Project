#include <stdio.h>

int maxSubarraySum(int vet[], int n) {
    int best_sum = 0;
    int sum = 0;
    for (int start = 0; start < n; ++start) {
        if (sum <= 0)
            sum = 0;
        sum += vet[start];
        if (sum > best_sum)
            best_sum = sum;
    }
    return best_sum;
}

int main() {
    int vet[] = {1, -3, 4, -2, -1, 6};
    int n = 6;
    printf("%d\n", maxSubarraySum(vet, n)); // Output should be 7
    return 0;
}
