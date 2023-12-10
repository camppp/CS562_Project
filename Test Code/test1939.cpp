#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::vector<int> sequence = {1, 2, 3, 4, 2, 3, 4, 5, 6, 7, 8, 9, 9};
    std::unordered_map<int, int> countMap;

    int ans = 0;
    int cnt = 0;

    for (int i : sequence) {
        if (countMap.find(i) == countMap.end()) {
            countMap[i] = 1;
            ans = i;
            cnt++;
        } else {
            countMap[i]++;
        }
    }

    if (cnt == 1) {
        std::cout << ans << std::endl;
    } else {
        std::cout << "Multiple unique integers found" << std::endl;
        for (auto it = countMap.begin(); it != countMap.end(); ++it) {
            std::cout << it->first << " " << it->second << std::endl;
        }
    }

    return 0;
}
