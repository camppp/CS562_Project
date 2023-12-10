#include <iostream>
#include <unordered_map>

struct IntPair {
    int first;
    int second;

    IntPair(int first, int second) : first(first), second(second) {}
};

// Custom hash function for IntPair
struct IntPairHash {
    std::size_t operator()(const IntPair& pair) const {
        return std::hash<int>()(pair.first) ^ std::hash<int>()(pair.second);
    }
};

// Custom equality comparison for IntPair
struct IntPairEqual {
    bool operator()(const IntPair& lhs, const IntPair& rhs) const {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
};

int main() {
    std::unordered_map<IntPair, int, IntPairHash, IntPairEqual> map;

    map.insert({IntPair(1, 2), 3});
    map.insert({IntPair(2, 3), 5});
    map.insert({IntPair(3, 4), 7});

    std::cout << map.at(IntPair(1, 2)) << std::endl; // Output: 3
    std::cout << map.at(IntPair(2, 3)) << std::endl; // Output: 5
    std::cout << map.at(IntPair(3, 4)) << std::endl; // Output: 7

    return 0;
}
