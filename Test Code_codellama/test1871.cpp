std::vector<std::pair<int, int>> mergeIntervals(std::vector<std::pair<int, int>> &intervals) {
    std::vector<std::pair<int, int>> mergedIntervals;

    // Sort the intervals by their start time
    std::sort(intervals.begin(), intervals.end(),
        [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
            return a.first < b.first;
        });

    // Iterate through the sorted intervals and merge overlapping ones
    for (auto it = intervals.begin(); it != intervals.end(); ++it) {
        // If the current interval overlaps with the previous one, merge them
        if (it != intervals.begin() && it->first <= std::prev(it)->second) {
            std::prev(it)->second = std::max(it->second, std::prev(it)->second);
        } else {
            // If the current interval does not overlap with the previous one, add it to the merged intervals
            mergedIntervals.push_back(*it);
        }
    }

    return mergedIntervals;
}
