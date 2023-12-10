#include <vector>

bool any_of(const std::vector<int>& vec, int target) {
    for (const auto& element : vec) {
        if (element == target) {
            return true;
        }
    }
    return false;
}
