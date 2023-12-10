#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 100;
int visited[MAX_N][MAX_N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<int> track;

bool isValid(int x, int y, int N, const vector<vector<int>>& maze) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0 && visited[x][y] == -1);
}

void BFS(int x, int y, int p, int q, int N, const vector<vector<int>>& maze) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 0;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        if (curX == p && curY == q) {
            int cur = visited[curX][curY];
            while (cur != 0) {
                track.push_back(cur);
                int nx = curX - dx[track.back() - 1];
                int ny = curY - dy[track.back() - 1];
                curX = nx;
                curY = ny;
                cur = visited[nx][ny];
            }
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newX = curX + dx[i];
            int newY = curY + dy[i];
            if (isValid(newX, newY, N, maze)) {
                visited[newX][newY] = visited[curX][curY] + 1;
                q.push({newX, newY});
            }
        }
    }
}

vector<int> shortestPath(int N, const vector<vector<int>>& maze, int x, int y, int p, int q) {
    memset(visited, -1, sizeof(visited));
    BFS(x, y, p, q, N, maze);
    reverse(track.begin(), track.end());
    return track;
}

int main() {
    int N = 3;
    vector<vector<int>> maze = {{0, 1, 0}, {0, 0, 0}, {1, 1, 0}};
    int x = 0, y = 0, p = 2, q = 2;
    vector<int> result = shortestPath(N, maze, x, y, p, q);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}
