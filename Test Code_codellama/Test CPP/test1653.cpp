#include <iostream>
#include <vector>
#include <cmath>

namespace statistics {
    double variance(const std::vector<double>& data) {
        double mean = 0;
        for (int i = 0; i < data.size(); i++) {
            mean += data[i];
        }
        mean /= data.size();

        double variance = 0;
        for (int i = 0; i < data.size(); i++) {
            variance += (data[i] - mean) * (data[i] - mean);
        }
        variance /= data.size();

        return variance;
    }
}
