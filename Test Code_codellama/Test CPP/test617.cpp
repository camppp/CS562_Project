#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }
    sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
    int e;
    cin >> e;
    for (int i = 0; i < e; i++) {
        int x;
        cin >> x;
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (pairs[j].first <= x) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
