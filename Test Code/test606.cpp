#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX_V = 100; // Maximum number of vertices

vector<vector<int>> capacity(MAX_V, vector<int>(MAX_V, 0));
vector<vector<int>> residual(MAX_V, vector<int>(MAX_V, 0));
vector<int> parent(MAX_V, -1);

void addEdge(int from, int to, int cap) {
    capacity[from][to] = cap;
}

bool bfs(int source, int sink, vector<int>& parent) {
    vector<bool> visited(MAX_V, false);
    vector<int> queue;
    queue.push_back(source);
    visited[source] = true;
    parent[source] = -1;

    while (!queue.empty()) {
        int u = queue.front();
        queue.erase(queue.begin());

        for (int v = 0; v < MAX_V; v++) {
            if (!visited[v] && residual[u][v] > 0) {
                queue.push_back(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[sink];
}

int fordFulkerson(int source, int sink) {
    int maxFlow = 0;

    while (bfs(source, sink, parent)) {
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residual[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    // Example usage
    int vertexNum = 4;
    addEdge(0, 1, 3);
    addEdge(0, 2, 2);
    addEdge(1, 2, 1);
    addEdge(1, 3, 3);
    addEdge(2, 3, 2);

    int ans = fordFulkerson(0, vertexNum - 1);
    cout << ans << endl;

    return 0;
}
