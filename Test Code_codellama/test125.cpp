#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

vector<int> shortestPathLength(const vector<vector<int>>& graph, int source) {
    vector<int> dist(graph.size(), INT_MAX);
    dist[source] = 0;

    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;
}

int main() {
    vector<vector<int>> graph = {{1, 2}, {3}, {4}, {1, 4}, {}};
    int source = 0;
    vector<int> dist = shortestPathLength(graph, source);
    for (int i = 0; i < dist.size(); i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}
