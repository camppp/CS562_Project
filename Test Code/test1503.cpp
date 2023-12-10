std::pair<int, int> simulateActorMovement(std::vector<std::vector<int>> grid, const std::string& commands) {
    int row = 0, col = 0;
    for (char command : commands) {
        switch (command) {
            case 'U':
                row--;
                break;
            case 'D':
                row++;
                break;
            case 'L':
                col--;
                break;
            case 'R':
                col++;
                break;
            default:
                break;
        }
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size()) {
            // Ignore movement if actor would exit the grid
            continue;
        }
        grid[row][col] = 0;
    }
    return {row, col};
}
