#include <iostream>
#include <vector>
#include <queue>

void run_game() {
    int N, M;
    std::cin >> N >> M; // Input dimensions of the maze

    std::vector<std::vector<char>> maze(N, std::vector<char>(M));
    int start_x, start_y, end_x, end_y;

    // Input the maze grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> maze[i][j];
            if (maze[i][j] == 'S') {
                start_x = i;
                start_y = j;
            } else if (maze[i][j] == 'E') {
                end_x = i;
                end_y = j;
            }
        }
    }

    // Define the four directions: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Perform BFS to find the shortest path from start to end
    std::queue<std::pair<int, int>> q;
    q.push({start_x, start_y});
    maze[start_x][start_y] = '#'; // Mark the starting point as visited

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M && maze[new_x][new_y] != '#' && maze[new_x][new_y] != 'S') {
                if (new_x == end_x && new_y == end_y) {
                    std::cout << "Player successfully reaches the end point." << std::endl;
                    return;
                }
                q.push({new_x, new_y});
                maze[new_x][new_y] = '#'; // Mark the cell as visited
            }
        }
    }

    std::cout << "Player cannot reach the end point." << std::endl;
}
