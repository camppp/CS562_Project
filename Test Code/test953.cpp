#include <utility>

std::pair<int, int> calculateSugar(int water, int sugar) {
    return std::make_pair(water + sugar, sugar);
}
