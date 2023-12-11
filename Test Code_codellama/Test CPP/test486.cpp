vector<int> longestIncreasingSubsequence(const vector<int>& a) {
    // Initialize the longest increasing subsequence with the first element
    vector<int> lis = {a[0]};

    // Iterate over the remaining elements of the input array
    for (int i = 1; i < a.size(); i++) {
        // If the current element is greater than the last element of the LIS,
        // add it to the LIS
        if (a[i] > lis.back()) {
            lis.push_back(a[i]);
        }
    }

    return lis;
}
