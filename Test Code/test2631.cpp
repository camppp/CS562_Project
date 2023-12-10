#include <iostream>
#include <vector>

std::vector<std::vector<int>> combine(const std::vector<std::vector<int>>& vv, unsigned int level, unsigned int nfs) {
    std::vector<std::vector<int>> result;
    if (level == 0) {
        result.push_back(std::vector<int>());
        return result;
    }

    for (unsigned int i = 0; i < vv.size(); ++i) {
        for (unsigned int j = vv[i].back() + 1; j <= nfs - level + 1; ++j) {
            std::vector<std::vector<int>> next_vv = vv;
            next_vv[i].push_back(j);
            std::vector<std::vector<int>> temp = combine(next_vv, level - 1, nfs);
            for (unsigned int k = 0; k < temp.size(); ++k) {
                result.push_back(temp[k]);
            }
        }
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> initial{{0}};
    unsigned int level = 3;
    unsigned int nfs = 5;
    std::vector<std::vector<int>> combinations = combine(initial, level, nfs);
    for (const auto& combination : combinations) {
        for (const auto& num : combination) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
