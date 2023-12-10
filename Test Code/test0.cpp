vector<int> convolution(vector<int> a, vector<int> b) {
    int n = a.size();
    vector<int> c(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; i++) {
        int sum = 0;
        for (int j = max(0, i - n + 1); j <= min(i, n - 1); j++) {
            sum += a[j] * b[i - j];
        }
        c[i] = sum;
    }
    return c;
}
