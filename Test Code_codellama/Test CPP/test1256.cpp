#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> prices) {
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) {
            maxProfit += prices[i] - prices[i - 1];
        }
    }
    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max profit: " << maxProfit(prices) << endl;
    return 0;
}
