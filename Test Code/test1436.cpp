java
public int maxProfit(int[] input) {
    int length = input.length;
    if (length == 0) {
        return 0; // No profit can be made with an empty array
    }

    int min_price = input[0]; // min price seen till now (on left)
    int max_profit = 0;

    for (int i = 1; i < length; i++) {
        int current_profit; // max profit right now (if we sell today) 0....i
        if (input[i] > min_price) {
            current_profit = input[i] - min_price;
            if (current_profit > max_profit) {
                max_profit = current_profit;
            }
        } else {
            min_price = input[i];
        }
    }

    return max_profit;
}
