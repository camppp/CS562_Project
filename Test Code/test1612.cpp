#include <vector>
#include <algorithm>

std::vector<uint32_t> transformAndSort(const uint32_t* u32Data, size_t sizeInU32) {
    // Create a vector from the input array
    std::vector<uint32_t> input(u32Data, u32Data + sizeInU32);

    // Double the value of each element in the array
    for (size_t i = 0; i < input.size(); ++i) {
        input[i] *= 2;
    }

    // Sort the array in non-decreasing order
    std::sort(input.begin(), input.end());

    return input;
}
