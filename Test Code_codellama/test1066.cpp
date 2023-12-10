int maxTotalWeight(int weights[], int n, int w) {
    int maxWeight = 0;
    for (int i = 0; i < n; i++) {
        if (weights[i] + maxWeight <= w) {
            maxWeight += weights[i];
        } else {
            break;
        }
    }
    return maxWeight;
}
