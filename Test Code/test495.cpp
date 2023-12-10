java
boolean canEscape(char[][] maze) {
    int rows = maze.length;
    int cols = maze[0].length;
    boolean[][] visited = new boolean[rows][cols];

    // Depth-first search to find a path from start to end
    return dfs(0, 0, maze, visited, rows, cols);
}

boolean dfs(int row, int col, char[][] maze, boolean[][] visited, int rows, int cols) {
    // Check if the current position is out of bounds or a wall, or already visited
    if (row < 0 || row >= rows || col < 0 || col >= cols || maze[row][col] == '#' || visited[row][col]) {
        return false;
    }

    // Mark the current position as visited
    visited[row][col] = true;

    // Check if the current position is the end
    if (row == rows - 1 && col == cols - 1) {
        return true;
    }

    // Try moving in all four directions
    if (dfs(row + 1, col, maze, visited, rows, cols) || dfs(row - 1, col, maze, visited, rows, cols) ||
        dfs(row, col + 1, maze, visited, rows, cols) || dfs(row, col - 1, maze, visited, rows, cols)) {
        return true;
    }

    // Unmark the current position as visited (backtrack)
    visited[row][col] = false;

    return false;
}
