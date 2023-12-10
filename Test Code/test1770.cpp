#include <iostream>
#include <vector>

std::pair<std::vector<unsigned>, std::vector<unsigned>> filterElements(const std::vector<unsigned>& A, unsigned average) {
    std::vector<unsigned> B, C;
    for (auto x : A) {
        if (x > average)
            B.push_back(x);
        else
            C.push_back(x);
    }
    return std::make_pair(B, C);
}

int main() {
    std::vector<unsigned> A = {10, 5, 8, 12, 3};
    unsigned average = 7;
    auto result = filterElements(A, average);
    std::cout << "B = {";
    for (auto x : result.first) {
        std::cout << x << " ";
    }
    std::cout << "}\nC = {";
    for (auto x : result.second) {
        std::cout << x << " ";
    }
    std::cout << "}" << std::endl;
    return 0;
}
