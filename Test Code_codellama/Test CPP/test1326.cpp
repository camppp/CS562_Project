#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, char>> pairs = {
        {3, 'c'},
        {1, 'a'},
        {2, 'b'}
    };

    // Sort the pairs based on the character in non-decreasing order
    sort(pairs.begin(), pairs.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
        return a.second < b.second;
    });

    // Print the integers in the sorted order
    for (const auto& pair : pairs) {
        cout << pair.first << " ";
    }

    return 0;
}
