#include <vector>

std::vector<int64_t> processMask(const int8_t* mask, int64_t length, bool validwhen) {
    std::vector<int64_t> toindex(length);
    for (int64_t i = 0; i < length; i++) {
        if (mask[i] != 0 && validwhen) {
            toindex[i] = i;
        } else if (mask[i] == 0 && !validwhen) {
            toindex[i] = -1;
        } else {
            toindex[i] = -1;
        }
    }
    return toindex;
}
