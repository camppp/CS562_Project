int findMaxThreshold(const std::vector<Threshold>& thresholds) {
    int maxThreshold = INT_MIN;  // Initialize with the smallest possible value

    for (const auto& threshold : thresholds) {
        if (threshold.m_threshold > maxThreshold) {
            maxThreshold = threshold.m_threshold;
        }
    }

    return maxThreshold;
}
