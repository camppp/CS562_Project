#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

class SSet {
private:
    std::vector<int> elements;

public:
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        int num;
        while (file >> num) {
            elements.push_back(num);
        }
        file.close();
    }

    bool checkZeroSumSlow() {
        int n = elements.size();
        for (int i = 0; i < (1 << n); i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    sum += elements[j];
                }
            }
            if (sum == 0) {
                return true;
            }
        }
        return false;
    }

    bool checkZeroSumFast() {
        std::unordered_set<int> sums;
        for (int num : elements) {
            std::unordered_set<int> newSums;
            for (int sum : sums) {
                newSums.insert(sum + num);
            }
            sums.insert(newSums.begin(), newSums.end());
            sums.insert(num);
            if (sums.count(0) > 0) {
                return true;
            }
        }
        return false;
    }
};
