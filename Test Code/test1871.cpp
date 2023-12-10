#include <vector>
#include <algorithm>

std::vector<std::pair<int, int>> mergeIntervals(std::vector<std::pair<int, int>> &intervals) {
    if (intervals.empty()) {
        return {};
    }

    std::sort(intervals.begin(), intervals.end());

    std::vector<std::pair<int, int>> merged;
    merged.push_back(intervals[0]);

    for (const auto &interval : intervals) {
        if (interval.first <= merged.back().second) {
            merged.back().second = std::max(merged.back().second, interval.second);
        } else {
            merged.push_back(interval);
        }
    }

    return merged;
}
