#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>

class MazeSolver {
public:
    std::vector<std::pair<int, int>> findShortestPath(const std::vector<std::vector<int>>& maze, 
                                                      std::pair<int, int> start, 
                                                      std::pair<int, int> end) {
        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        std::queue<std::pair<int, int>> q;
        std::unordered_map<std::pair<int, int>, std::pair<int, int>> parent;
        q.push(start);
        parent[start] = start;

        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            if (current == end) {
                break;
            }
            for (const auto& dir : directions) {
                int x = current.first + dir.first;
                int y = current.second + dir.second;
                if (x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] == 0 && parent.find({x, y}) == parent.end()) {
                    q.push({x, y});
                    parent[{x, y}] = current;
                }
            }
        }

        std::vector<std::pair<int, int>> shortestPath;
        if (parent.find(end) == parent.end()) {
            return shortestPath;  // No path found
        }
        auto current = end;
        while (current != start) {
            shortestPath.push_back(current);
            current = parent[current];
        }
        shortestPath.push_back(start);
        std::reverse(shortestPath.begin(), shortestPath.end());
        return shortestPath;
    }
};
