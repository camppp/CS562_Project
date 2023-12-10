#include <vector>
#include <string>
#include <utility>

std::pair<int, int> simulateActorMovement(std::vector<std::vector<int>> grid, const std::string& commands) {
    int rows = grid.size();
    int cols = grid[0].size();
    int x = 0, y = 0;

    for (char command : commands) {
        if (command == 'U' && x > 0 && grid[x - 1][y] == 1) {
            x--;
        } else if (command == 'D' && x < rows - 1 && grid[x + 1][y] == 1) {
            x++;
        } else if (command == 'L' && y > 0 && grid[x][y - 1] == 1) {
            y--;
        } else if (command == 'R' && y < cols - 1 && grid[x][y + 1] == 1) {
            y++;
        }
    }

    return std::make_pair(x, y);
}
