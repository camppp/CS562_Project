#include <vector>
#include <cstdint>

uint64_t part_two(const std::vector<int> &inputs) {
    uint64_t sum = 0;
    for (int num : inputs) {
        if (num % 2 == 0) {
            sum += num;
        }
    }
    return sum;
}
