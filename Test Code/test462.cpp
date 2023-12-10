#include <iostream>
#include <unordered_map>

// Define the IntPair data structure
struct IntPair {
    int first;
    int second;

    // Custom hash function for IntPair
    struct IntPairHash {
        size_t operator()(const IntPair& p) const {
            return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
        }
    };

    // Custom equality comparison for IntPair
    struct IntPairEqual {
        bool operator()(const IntPair& p1, const IntPair& p2) const {
            return p1.first == p2.first && p1.second == p2.second;
        }
    };
};

// Define the unordered_map using IntPair as key
typedef std::unordered_map<IntPair, int, IntPair::IntPairHash, IntPair::IntPairEqual> Pair2IntMap;

int main() {
    // Create an instance of IntPair
    IntPair pair1 = {1, 2};
    IntPair pair2 = {3, 4};

    // Create an unordered_map using IntPair as key
    Pair2IntMap pairMap;
    pairMap[pair1] = 10;
    pairMap[pair2] = 20;

    // Access values using IntPair keys
    std::cout << "Value for pair1: " << pairMap[pair1] << std::endl;
    std::cout << "Value for pair2: " << pairMap[pair2] << std::endl;

    return 0;
}
