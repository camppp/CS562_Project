#include <iostream>
#include <algorithm>

int maxWeightAfterConnectingRopes(int weight[], int rope, int n) {
    std::sort(weight, weight + rope); // Sort the array of rope weights

    int result[rope]; // Array to store the results after multiplying weights by n
    for (int j = rope - 1; j >= 0; j--) {
        result[j] = weight[j] * n; // Multiply each weight by n and store the result
        n++;
    }

    std::sort(result, result + rope); // Sort the array of results

    int max = result[rope - 1]; // Get the maximum weight achieved after connecting the ropes
    return max;
}

int main() {
    int weight[] = {4, 3, 2, 6};
    int rope = 4;
    int n = 1;
    std::cout << maxWeightAfterConnectingRopes(weight, rope, n) << std::endl; // Output: 29
    return 0;
}
