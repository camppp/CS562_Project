bool isPath(int m, int n, char maze[10][10]) {
    // Initialize a queue to store the cells to be visited
    queue<pair<int, int>> q;

    // Enqueue the starting cell
    q.push(make_pair(0, 0));

    // Initialize a set to keep track of the visited cells
    set<pair<int, int>> visited;

    // Loop until the queue is empty
    while (!q.empty()) {
        // Dequeue the current cell
        pair<int, int> current = q.front();
        q.pop();

        // If the current cell is the goal cell, return true
        if (current.first == m - 1 && current.second == n - 1) {
            return true;
        }

        // If the current cell is not blocked, mark it as visited and enqueue its neighbors
        if (maze[current.first][current.second] != 'X') {
            visited.insert(current);
            if (current.first + 1 < m && maze[current.first + 1][current.second] != 'X') {
                q.push(make_pair(current.first + 1, current.second));
            }
            if (current.second + 1 < n && maze[current.first][current.second + 1] != 'X') {
                q.push(make_pair(current.first, current.second + 1));
            }
        }
    }

    // If the queue is empty and no path was found, return false
    return false;
}
