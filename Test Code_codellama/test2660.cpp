c
int bfs(int start_city, int city_concern) {
    int count = 0;
    bool visited[MAX_CITIES];  // boolean array to track if a city is visited
    queue<int> q;  // queue to store cities to visit

    // Initialize visited array and queue
    for (int i = 0; i < MAX_CITIES; i++) {
        visited[i] = false;
    }
    q.push(start_city);

    // Breadth-first search
    while (!q.empty()) {
        int city = q.front();
        q.pop();
        if (visited[city] == false) {
            visited[city] = true;
            count++;
            // Add neighbors of city to queue
            for (int i = 0; i < MAX_CITIES; i++) {
                if (adjacency_list[city][i] == true && visited[i] == false) {
                    q.push(i);
                }
            }
        }
    }

    // Return the number of connected components
    return count;
}
