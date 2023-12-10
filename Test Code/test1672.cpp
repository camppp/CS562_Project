#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct edge {
    int to, flow, cap;
    double cost;
    edge(const int _to, const int _flow, const int _cap, const double _cost) :
        to(_to), flow(_flow), cap(_cap), cost(_cost) {}
};

double dist[N];
vector<int> g[N];
vector<edge> edges;
vector<member> members;
int seen[N], parent[M];
int n, m, source, sink, current;

double minCostAssignment() {
    double totalCost = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            edges.push_back(edge(i, 0, 1, members[i].cost[j] + tasks[j].cost[i]));
            g[i].push_back(edges.size() - 1);
            edges.push_back(edge(j + n, 0, 1, 0));
            g[j + n].push_back(edges.size() - 1);
        }
    }

    source = n + m;
    sink = n + m + 1;

    for (int i = 0; i < n; ++i) {
        edges.push_back(edge(source, 0, 1, 0));
        g[source].push_back(edges.size() - 1);
    }

    for (int i = 0; i < m; ++i) {
        edges.push_back(edge(i + n, 0, 1, 0));
        g[i + n].push_back(edges.size() - 1);
    }

    while (true) {
        // Implement min cost max flow algorithm (e.g., using Dijkstra's algorithm)
        // Update flow and cost
        // Break when no augmenting path is found
    }

    for (int i = 0; i < edges.size(); ++i) {
        if (edges[i].flow > 0 && edges[i].to != source && edges[i].to != sink) {
            totalCost += edges[i].cost;
        }
    }

    return totalCost;
}
