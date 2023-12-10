#include <cmath>

std::tuple<int, int, double> calculateAddress(int value, int step) {
    double address = (value / step) - 1;
    int index = std::floor(address);
    double proportion = address - index;
    return std::make_tuple(index, index, proportion);
}
