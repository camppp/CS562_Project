#include <iostream>
#include <vector>
#include <unordered_set>

namespace vinum::operators::aggregate {
    double calculateAverage(const std::vector<int>& input) {
        if (input.empty()) {
            return 0;
        }

        std::unordered_set<int> uniqueValues;
        int sum = 0;

        for (int num : input) {
            if (uniqueValues.insert(num).second) {
                sum += num;
            }
        }

        return static_cast<double>(sum) / uniqueValues.size();
    }
}  // namespace vinum::operators::aggregate
