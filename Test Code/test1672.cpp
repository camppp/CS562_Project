double minCostAssignment() {
    // Initialize the distance array and the parent array
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[source] = 0;

    // Loop until a fixpoint is reached
    while (true) {
        // Relax each edge
        for (int i = 0; i < m; i++) {
            int u = edges[i].from;
            int v = edges[i].to;
            double cost = edges[i].cost;
            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                parent[v] = u;
            }
        }

        // Check if a fixpoint is reached
        bool fixpoint = true;
        for (int i = 0; i < m; i++) {
            int u = edges[i].from;
            int v = edges[i].to;
            double cost = edges[i].cost;
            if (dist[u] + cost < dist[v]) {
                fixpoint = false;
                break;
            }
        }
        if (fixpoint) {
            break;
        }
    }

    // Find the minimum cost path from the source node to each task node
    double minCost = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].from;
        int v = edges[i].to;
        double cost = edges[i].cost;
        if (dist[u] + cost < dist[v]) {
            minCost += cost;
        }
    }

    return minCost;
}
