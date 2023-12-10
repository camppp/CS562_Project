#include <iostream>
#include <utility>

std::pair<int, int> calculateSugar(int water, int sugar) {
    int total = water + sugar;
    return std::make_pair(total, sugar);
}

int main() {
    int water = 5, sugar = 3;
    std::pair<int, int> result = calculateSugar(water, sugar);
    std::cout << result.first << " " << result.second << std::endl;
    return 0;
}
