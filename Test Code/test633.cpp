#include <vector>
#include <cstdint>

uint64_t part_two(const std::vector<int> &inputs) {
    uint64_t sum = 0;
    for (int i = 0; i < inputs.size(); i++) {
        if (inputs[i] % 2 == 0) {
            sum += inputs[i];
        }
    }
    return sum;
}
