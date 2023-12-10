#include <vector>
#include <queue>
#include <utility>

int shortestPath(std::vector<std::vector<int>>& maze, int start_row, int start_col, int end_row, int end_col) {
    int rows = maze.size();
    int cols = maze[0].size();
    std::vector<std::vector<int>> distance(rows, std::vector<int>(cols, -1));
    std::queue<std::pair<int, int>> q;
    q.push({start_row, start_col});
    distance[start_row][start_col] = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        if (r == end_row && c == end_col) {
            return distance[r][c];
        }
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && maze[nr][nc] == 0 && distance[nr][nc] == -1) {
                q.push({nr, nc});
                distance[nr][nc] = distance[r][c] + 1;
            }
        }
    }
    return -1;  // No path found
}
