#include <vector>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

bool isPeak(int x, int y, const vector<vector<int>>& grid) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size()) {
            if (grid[nx][ny] >= grid[x][y]) {
                return false;
            }
        }
    }
    return true;
}

int countPeaks(vector<vector<int>>& grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (isPeak(i, j, grid)) {
                count++;
            }
        }
    }
    return count;
}
