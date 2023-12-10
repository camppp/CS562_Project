#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> getMinimumSumPairs(vector<int> a) {
    vector<pair<int, int>> pairs;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            pairs.push_back(make_pair(i, j));
        }
    }
    sort(pairs.begin(), pairs.end(), [](pair<int, int> p1, pair<int, int> p2) {
        return p1.first + p1.second < p2.first + p2.second;
    });
    return pairs;
}

int main() {
    vector<int> a = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    vector<pair<int, int>> pairs = getMinimumSumPairs(a);
    for (pair<int, int> p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    return 0;
}
