#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> labelComponents(vector<vector<int>> grid) {
    int numZones = grid.size();
    vector<vector<int>> labeledGrid(numZones, vector<int>(numZones));

    for (int i = 0; i < numZones; i++) {
        for (int j = 0; j < numZones; j++) {
            if (grid[i][j] != 0) {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                labeledGrid[i][j] = grid[i][j];

                while (!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();

                    if (labeledGrid[curr.first][curr.second] != 0) {
                        continue;
                    }

                    labeledGrid[curr.first][curr.second] = grid[curr.first][curr.second];

                    if (curr.first > 0 && grid[curr.first - 1][curr.second] != 0 && labeledGrid[curr.first - 1][curr.second] == 0) {
                        q.push(make_pair(curr.first - 1, curr.second));
                    }

                    if (curr.second > 0 && grid[curr.first][curr.second - 1] != 0 && labeledGrid[curr.first][curr.second - 1] == 0) {
                        q.push(make_pair(curr.first, curr.second - 1));
                    }

                    if (curr.first < numZones - 1 && grid[curr.first + 1][curr.second] != 0 && labeledGrid[curr.first + 1][curr.second] == 0) {
                        q.push(make_pair(curr.first + 1, curr.second));
                    }

                    if (curr.second < numZones - 1 && grid[curr.first][curr.second + 1] != 0 && labeledGrid[curr.first][curr.second + 1] == 0) {
                        q.push(make_pair(curr.first, curr.second + 1));
                    }
                }
            }
        }
    }

    return labeledGrid;
}
