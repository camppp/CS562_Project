#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> findMissingNumbers(const vector<vector<int>>& grid) {
    vector<pair<int, int>> missingNumbers;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == -1) {
                missingNumbers.push_back(make_pair(i, j));
            }
        }
    }

    return missingNumbers;
}

int main() {
    vector<vector<int>> grid = {
        {13, 15, 12, 29, 49, -1, 51, 33, 50},
        {14, 30, -1, 50, 52, 49, 15, 34, 53},
        {14, 16, -1, 31, 51, 17, 53, 35, 52},
        {15, 32, 16, 52, 54, 51, 17, 36, 55},
        {16, 18, 15, 33, 53, -1, 55, 37, 54},
        {17, 34, -1, 54, 56, 53, 18, 38, 57}
    };

    vector<pair<int, int>> missingNumbers = findMissingNumbers(grid);

    for (int i = 0; i < missingNumbers.size(); i++) {
        cout << "Missing number at position (" << missingNumbers[i].first << ", " << missingNumbers[i].second << ")" << endl;
    }

    return 0;
}
