int maxProfit(int input[]) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] < minPrice) {
            minPrice = input[i];
        } else if (input[i] - minPrice > maxProfit) {
            maxProfit = input[i] - minPrice;
        }
    }

    return maxProfit;
}
