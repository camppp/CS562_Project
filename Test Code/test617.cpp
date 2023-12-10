#include <iostream>
#include <vector>
#include <algorithm>

struct Pair {
    long long int a, b;
    bool operator<(const Pair& other) const {
        return a < other.a;
    }
};

int main() {
    int N, E;
    std::cin >> N;
    std::vector<Pair> pairs(N);
    for (int i = 0; i < N; ++i) {
        long long int a, b;
        std::cin >> a >> b;
        pairs[i].a = a;
        pairs[i].b = b;
    }

    std::sort(pairs.begin(), pairs.end());

    std::cin >> E;
    for (int i = 0; i < E; ++i) {
        long long int x;
        std::cin >> x;
        int count = 0;
        for (const auto& pair : pairs) {
            if (pair.a <= x) {
                count++;
            } else {
                break;
            }
        }
        std::cout << count << std::endl;
    }

    return 0;
}
