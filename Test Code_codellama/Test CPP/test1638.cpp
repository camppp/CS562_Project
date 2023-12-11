int minStepsToReachDestination(vector<vector<int>>& maze, int x, int y) {
    int rows = maze.size();
    int cols = maze[0].size();

    // Initialize the distance array with infinite distance
    vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
    distance[0][0] = 0;

    // Initialize the queue with the starting cell
    queue<pair<int, int>> q;
    q.push({0, 0});

    // Loop until the queue is empty
    while (!q.empty()) {
        // Get the current cell from the queue
        pair<int, int> current = q.front();
        q.pop();

        // Check if the current cell is the destination cell
        if (current.first == x && current.second == y) {
            return distance[current.first][current.second];
        }

        // Loop through the neighboring cells
        for (int i = 0; i < 4; i++) {
            int newRow = current.first + (i == 0 || i == 2 ? 1 : -1);
            int newCol = current.second + (i == 1 || i == 3 ? 1 : -1);

            // Check if the neighboring cell is valid and not blocked
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && maze[newRow][newCol] == 0) {
                // Update the distance array and queue with the new cell
                distance[newRow][newCol] = min(distance[newRow][newCol], distance[current.first][current.second] + 1);
                q.push({newRow, newCol});
            }
        }
    }

    // If the destination cell is not reachable, return -1
    return -1;
}
