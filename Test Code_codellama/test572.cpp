#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> shortestPaths(int n, int m, vector<int> u, vector<int> v, vector<int> l) {
    vector<int> dis(n, INT_MAX);
    dis[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dis[node] != INT_MAX) {
            continue;
        }

        dis[node] = dist;

        for (int i = 0; i < m; i++) {
            if (u[i] == node) {
                int newNode = v[i];
                int newDist = dist + l[i];
                if (newDist < dis[newNode]) {
                    dis[newNode] = newDist;
                    pq.push({newDist, newNode});
                }
            }
        }
    }

    return dis;
}
