#include <vector>
#include <queue>
#include <algorithm>

int maxFlow(int N, int S, int T, vector<vector<int>>& cap) {
    int flow = 0;
    vector<vector<int>> residualCap = cap;
    vector<int> prev(N);

    while (true) {
        fill(prev.begin(), prev.end(), -1);
        queue<int> q;
        q.push(S);
        prev[S] = -2;

        while (!q.empty() && prev[T] == -1) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < N; v++) {
                if (prev[v] == -1 && residualCap[u][v] > 0) {
                    q.push(v);
                    prev[v] = u;
                }
            }
        }

        if (prev[T] == -1) {
            break;
        }

        int pathFlow = INT_MAX;
        for (int v = T; v != S; v = prev[v]) {
            int u = prev[v];
            pathFlow = min(pathFlow, residualCap[u][v]);
        }

        for (int v = T; v != S; v = prev[v]) {
            int u = prev[v];
            residualCap[u][v] -= pathFlow;
            residualCap[v][u] += pathFlow;
        }

        flow += pathFlow;
    }

    return flow;
}
