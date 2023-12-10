#include <vector>
#include <queue>
#include <limits>
using namespace std;

vector<int> shortestPaths(int n, int m, vector<int> u, vector<int> v, vector<int> l) {
    int MAX = 99999999;
    vector<int> dis(n + 1, MAX);
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        adj[u[i]].push_back({v[i], l[i]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dis[1] = 0;

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > dis[node]) continue;

        for (auto edge : adj[node]) {
            int nextNode = edge.first;
            int weight = edge.second;
            if (dis[nextNode] > dis[node] + weight) {
                dis[nextNode] = dis[node] + weight;
                pq.push({dis[nextNode], nextNode});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dis[i] == MAX) dis[i] = -1;
    }

    return vector<int>(dis.begin() + 1, dis.end());
}
