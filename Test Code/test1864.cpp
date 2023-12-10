#include <vector>
#include <algorithm>

bool any_of(const std::vector<int>& vec, int target) {
    return std::any_of(vec.begin(), vec.end(), [target](int val) { return val == target; });
}
