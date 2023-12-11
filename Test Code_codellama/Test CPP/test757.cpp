#include <vector>
#include <utility>
#include <queue>
#include <iostream>

class MazeSolver {
public:
    std::vector<std::pair<int, int>> findShortestPath(const std::vector<std::vector<int>>& maze, 
                                                      std::pair<int, int> start, 
                                                      std::pair<int, int> end) {
        // Initialize the distance and previous map
        std::vector<std::vector<int>> distance(maze.size(), std::vector<int>(maze[0].size(), INT_MAX));
        std::vector<std::vector<std::pair<int, int>>> previous(maze.size(), std::vector<std::pair<int, int>>(maze[0].size(), std::make_pair(-1, -1)));

        // Initialize the queue with the start position
        std::queue<std::pair<int, int>> queue;
        queue.push(start);

        // Loop until the queue is empty
        while (!queue.empty()) {
            // Get the current position from the queue
            std::pair<int, int> current = queue.front();
            queue.pop();

            // If the current position is the end position, return the path
            if (current == end) {
                std::vector<std::pair<int, int>> path;
                while (current != start) {
                    path.push_back(current);
                    current = previous[current.first][current.second];
                }
                path.push_back(start);
                return path;
            }

            // Update the distance and previous map for the current position
            distance[current.first][current.second] = 0;
            previous[current.first][current.second] = current;

            // Add the neighbors of the current position to the queue
            for (int i = 0; i < 4; i++) {
                std::pair<int, int> neighbor = current;
                switch (i) {
                    case 0: neighbor.first--; break;
                    case 1: neighbor.first++; break;
                    case 2: neighbor.second--; break;
                    case 3: neighbor.second++; break;
                }
                if (maze[neighbor.first][neighbor.second] == 0 && distance[neighbor.first][neighbor.second] == INT_MAX) {
                    queue.push(neighbor);
                    distance[neighbor.first][neighbor.second] = distance[current.first][current.second] + 1;
                    previous[neighbor.first][neighbor.second] = current;
                }
            }
        }

        // If the end position is not found, return an empty path
        return {};
    }
};

int main() {
    // Example usage of the MazeSolver class
    MazeSolver solver;
    std::vector<std::vector<int>> maze = {
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };
    std::pair<int, int> start = {0, 0};
    std::pair<int, int> end = {4, 4};
    std::vector<std::pair<int, int>> shortestPath = solver.findShortestPath(maze, start, end);
    // Output the shortest path
    for (const auto& point : shortestPath) {
        std::cout << "(" << point.first << ", " << point.second << ") ";
    }
    return 0;
}
