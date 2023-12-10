#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPath(vector<vector<int>>& maze, int start_row, int start_col, int end_row, int end_col) {
    // Initialize the distance array with infinite values
    vector<vector<int>> dist(maze.size(), vector<int>(maze[0].size(), INT_MAX));

    // Initialize the queue with the start cell
    queue<pair<int, int>> q;
    q.push({start_row, start_col});

    // Set the distance of the start cell to 0
    dist[start_row][start_col] = 0;

    // Loop until the queue is empty
    while (!q.empty()) {
        // Get the current cell from the queue
        pair<int, int> curr = q.front();
        q.pop();

        // If the current cell is the end cell, return the distance
        if (curr.first == end_row && curr.second == end_col) {
            return dist[curr.first][curr.second];
        }

        // Loop through the neighboring cells
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // If the neighboring cell is valid and not blocked, add it to the queue
                int row = curr.first + i;
                int col = curr.second + j;
                if (row >= 0 && row < maze.size() && col >= 0 && col < maze[0].size() && maze[row][col] == 0) {
                    q.push({row, col});
                    dist[row][col] = dist[curr.first][curr.second] + 1;
                }
            }
        }
    }

    // If no path exists, return -1
    return -1;
}
