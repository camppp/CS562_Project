int maxFlow(int N, int S, int T, vector<vector<int>>& cap) {
    int flow = 0;
    while (true) {
        // Find an augmenting path
        for (int i = 0; i < N; i++) prev[i] = -1;
        queue<int> q;
        q.push(S); prev[S] = -2;
        while (!q.empty() && prev[T] == -1) {
            int u = q.front(), v; q.pop();
            for (int i = 0; i < deg[u]; i++) if (prev[v = adj[u][i]] == -1 && cap[u][v])
                q.push(v), prev[v] = u;
        }

        // If no augmenting path is found, stop
        if (prev[T] == -1) break;

        // Compute the flow along the augmenting path
        int pathFlow = INF;
        for (int v = T; v != S; v = prev[v]) {
            int u = prev[v];
            pathFlow = min(pathFlow, cap[u][v] - flow[u][v]);
        }

        // Update the flow
        for (int v = T; v != S; v = prev[v]) {
            int u = prev[v];
            flow[u][v] += pathFlow;
            flow[v][u] -= pathFlow;
        }

        // Update the residual capacities
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (prev[i] == -1 || prev[j] == -1) continue;
            cap[i][j] -= flow[i][j];
            cap[j][i] -= flow[j][i];
        }
    }
    return flow;
}
