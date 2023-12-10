vector<int> countElementsLessThanX(int a[], int n, int queries[], int q) {
    vector<int> counts(q);
    for (int i = 0; i < q; i++) {
        int x = queries[i];
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] < x) {
                count++;
            }
        }
        counts[i] = count;
    }
    return counts;
}
