#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int minStepsToReachDestination(vector<vector<int>>& maze, int x, int y) {
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<tuple<int, int, int>> todo;
    unordered_set<string> visited;
    visited.insert("0,0");
    todo.emplace(0, 0, 0);

    while (!todo.empty()) {
        auto [row, col, steps] = todo.front();
        todo.pop();

        if (row == x && col == y) {
            return steps;
        }

        for (const auto& dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && maze[newRow][newCol] == 0) {
                string newPos = to_string(newRow) + "," + to_string(newCol);
                if (visited.find(newPos) == visited.end()) {
                    visited.insert(newPos);
                    todo.emplace(newRow, newCol, steps + 1);
                }
            }
        }
    }

    return -1;  // If the bottom-right cell is unreachable
}
