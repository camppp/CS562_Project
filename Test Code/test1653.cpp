#include <iostream>
#include <vector>
#include <cmath>

namespace statistics {
    double mean(const std::vector<double>& data) {
        double sum = 0.0;
        for (const auto& value : data) {
            sum += value;
        }
        return sum / data.size();
    }

    double variance(const std::vector<double>& data) {
        double mean_value = mean(data);
        double sum_squared_diff = 0.0;
        for (const auto& value : data) {
            sum_squared_diff += (value - mean_value) * (value - mean_value);
        }
        return sum_squared_diff / data.size();
    }
}

int main() {
    std::vector<double> num_friends = { 15, 20, 25, 30, 35 };
    std::cout << "Variance: " << statistics::variance(num_friends) << "\n";
    return 0;
}
