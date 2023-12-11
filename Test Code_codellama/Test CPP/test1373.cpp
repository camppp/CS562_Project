int tlsort() {
    // Initialize the indegree array
    for (int i = 0; i < n; i++) {
        indegrees[i] = 0;
    }

    // Calculate the indegrees of all vertices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                indegrees[j]++;
            }
        }
    }

    // Check if the graph contains a cycle
    for (int i = 0; i < n; i++) {
        if (indegrees[i] == 0) {
            return -1;
        }
    }

    // Perform topological sorting
    vector<int> order;
    for (int i = 0; i < n; i++) {
        if (indegrees[i] == 0) {
            order.push_back(i);
            for (int j = 0; j < n; j++) {
                if (graph[i][j] != 0) {
                    indegrees[j]--;
                }
            }
        }
    }

    // Check if the topological sorting is valid
    for (int i = 0; i < n; i++) {
        if (indegrees[i] != 0) {
            return -1;
        }
    }

    // Return the topological ordering
    return order;
}
