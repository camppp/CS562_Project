#include <iostream>
#include <vector>

std::vector<int> customRandom(int seed, int a, int c, int m) {
    std::vector<int> randomSequence;
    int current = seed;
    for (int i = 0; i < 10; ++i) {
        current = (a * current + c) % m;
        randomSequence.push_back(current);
    }
    return randomSequence;
}

int main() {
    int seed = 3, a = 7, c = 3, m = 10;
    std::vector<int> result = customRandom(seed, a, c, m);
    for (int num : result) {
        std::cout << num << " ";
    }
    return 0;
}
