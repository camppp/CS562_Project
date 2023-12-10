double findMaxAbsoluteValue(std::vector<std::vector<std::vector<double>>> values_, uint32_t n, uint32_t m, uint32_t p) {
    double maxAbsValue = 0.0;
    for (uint32_t i = 0; i < n; i++) {
        for (uint32_t j = 0; j < m; j++) {
            for (uint32_t k = 0; k < p; k++) {
                double absValue = std::abs(values_[i][j][k]);
                if (absValue > maxAbsValue) {
                    maxAbsValue = absValue;
                }
            }
        }
    }
    return maxAbsValue;
}
