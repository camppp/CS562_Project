#include <vector>
#include <cstdint>

int processTuples(const std::vector<int>& sig, const std::vector<std::vector<int>>& tup) {
    int result = 0;
    for (const auto& tuple : tup) {
        int equation = 0;
        for (size_t i = 0; i < tuple.size(); i++) {
            equation |= sig[i] * tuple[i];
        }
        result &= equation;
    }
    return result;
}
