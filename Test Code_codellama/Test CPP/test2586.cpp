#include <vector>
#include <algorithm>

std::vector<bool> transform_data(const std::vector<bool>& input) {
    std::vector<bool> result;
    std::adjacent_find(input.begin(), input.end(), [](bool a, bool b) { return a == b; });
    for (auto it = input.begin(); it != input.end(); it++) {
        if (*it) {
            result.push_back(*it);
            break;
        }
    }
    std::copy_if(input.begin(), input.end(), std::back_inserter(result), [](bool a) { return a; });
    return result;
}
