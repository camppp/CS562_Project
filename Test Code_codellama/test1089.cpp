vector<int> MaxK(int arr[], int n, int k) {
    vector<int> result;
    for (int i = 0; i < n; i += k) {
        int max_val = arr[i];
        for (int j = i + 1; j < i + k; j++) {
            if (arr[j] > max_val) {
                max_val = arr[j];
            }
        }
        result.push_back(max_val);
    }
    return result;
}
