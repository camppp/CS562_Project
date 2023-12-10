#include <iostream>
#include <vector>

using namespace std;

tuple<float, vector<int>> findBestError(const vector<int>& dp, float best_err) {
    vector<int> best_dp;
    float best_err_value = 0.0f;

    for (int i = 0; i < dp.size(); i++) {
        if (dp[i] < best_err_value) {
            best_err_value = dp[i];
            best_dp = dp.substr(i);
        }
    }

    return make_tuple(best_err_value, best_dp);
}

int main() {
    vector<int> dp = {10, 15, 8, 12};
    float best_err = 0.05;

    auto result = findBestError(dp, best_err);

    cout << "Best error: " << get<0>(result) << endl;
    cout << "Best dynamic programming array: ";
    for (int i = 0; i < get<1>(result).size(); i++) {
        cout << get<1>(result)[i] << " ";
    }
    cout << endl;

    return 0;
}
