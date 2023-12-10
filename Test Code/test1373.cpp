#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1005; // Maximum number of vertices

int graph[MAXN][MAXN]; // Adjacency matrix representing the graph
int indegrees[MAXN];    // Array to store the indegree of each vertex
int n;                  // Number of vertices in the graph

int tlsort() {
    vector<int> order; // Stores the topological order of vertices
    queue<int> q;      // Queue to perform BFS for topological sorting

    for (int i = 0; i < n; i++) {
        if (indegrees[i] == 0) {
            q.push(i); // Add vertices with indegree 0 to the queue
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u); // Add the vertex to the topological order

        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0) {
                indegrees[v]--; // Decrement the indegree of adjacent vertices
                if (indegrees[v] == 0) {
                    q.push(v); // Add vertices with updated indegree 0 to the queue
                }
            }
        }
    }

    if (order.size() != n) {
        return -1; // Graph contains a cycle, return -1
    } else {
        return order.size(); // Return the number of vertices in the topological order
    }
}

int main() {
    // Input graph and indegrees
    // ...

    int result = tlsort();
    if (result == -1) {
        cout << "Impossible\n";
    } else {
        cout << result << '\n';
    }

    return 0;
}
