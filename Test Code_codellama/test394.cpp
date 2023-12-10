q[0][1] = j;
q[0][2] = k;
for (int l = 0, r = 1; l < r; ) {
    int u = q[l][0], v = q[l][1], w = q[l][2]; l++;

    // Check if the current node is the source node
    if (u == source) {
        // Update the distance for the source node
        dist[u] = 0;
    }

    // Check if the current node is already in the queue
    if (dist[u] != INT_MAX) {
        // Update the distance for the current node
        dist[u] = min(dist[u], w);

        // Add the neighbors of the current node to the queue
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (dist[v] == INT_MAX) {
                q[r][0] = v;
                q[r][1] = w;
                r++;
            }
        }
    }
}
