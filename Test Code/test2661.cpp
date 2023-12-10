#include <vector>

std::vector<double> get_vol_TS(const std::vector<double>& time_series) {
    std::vector<double> volumes;
    for (size_t i = 0; i < time_series.size() - 1; ++i) {
        double volume = 0.5 * (time_series[i] + time_series[i + 1]);
        volume *= 1.0; // Assuming time indices are 1 unit apart
        volumes.push_back(volume);
    }
    return volumes;
}
