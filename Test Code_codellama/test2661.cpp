std::vector<double> get_vol_TS(const std::vector<double>& time_series) {
    std::vector<double> volume(time_series.size() - 1);
    for (int i = 1; i < time_series.size(); i++) {
        volume[i - 1] = (time_series[i] + time_series[i - 1]) / 2 * (time_series[i + 1] - time_series[i - 1]);
    }
    return volume;
}
