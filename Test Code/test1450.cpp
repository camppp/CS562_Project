vector<int> findSubarray(vector<int> &arr, int targetSum) {
    int n = arr.size();
    vector<int> prefixSums(n + 1);
    prefixSums[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefixSums[i] = prefixSums[i - 1] + arr[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        int j = i + 1;
        while (j <= n && prefixSums[j] - prefixSums[i] < targetSum) {
            j++;
        }
        if (prefixSums[j] - prefixSums[i] == targetSum) {
            return {i, j};
        }
    }

    return {};
}
