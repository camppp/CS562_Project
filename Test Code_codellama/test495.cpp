bool canEscape(char[][] maze) {
    int rows = maze.length;
    int cols = maze[0].length;

    // Initialize the queue with the starting position
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    // Initialize the visited array
    bool visited[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            visited[i][j] = false;
        }
    }

    // Breadth-first search
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        // If the current position is the end position, return true
        if (curr.first == rows - 1 && curr.second == cols - 1) {
            return true;
        }

        // Mark the current position as visited
        visited[curr.first][curr.second] = true;

        // Add the neighboring positions to the queue
        for (int i = 0; i < 4; i++) {
            int newRow = curr.first + dirs[i].first;
            int newCol = curr.second + dirs[i].second;
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !visited[newRow][newCol] && maze[newRow][newCol] != '#') {
                q.push(make_pair(newRow, newCol));
            }
        }
    }

    // If the queue is empty, return false
    return false;
}
