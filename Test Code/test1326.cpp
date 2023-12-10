#include <iostream>
#include <vector>
#include <algorithm>

bool sortbysec(const std::pair<int, char> &a, const std::pair<int, char> &b) {
    return a.second < b.second;
}

void printSortedIntegers(const std::vector<std::pair<int, char>> &s) {
    std::vector<std::pair<int, char>> sorted = s;
    std::sort(sorted.begin(), sorted.end(), sortbysec);

    for (const auto &pair : sorted) {
        std::cout << pair.first << " ";
    }
}

int main() {
    std::vector<std::pair<int, char>> pairs = {{3, 'c'}, {1, 'a'}, {2, 'b'}};
    printSortedIntegers(pairs);
    return 0;
}
