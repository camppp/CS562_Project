#ifndef INCLUDED_UTILITIES_TARJAN_HPP
#define INCLUDED_UTILITIES_TARJAN_HPP

#include <vector>
#include <stack>
#include <algorithm>

class TarjanSCC {
    int n; // Number of vertices
    std::vector<std::vector<int>> graph;
    std::vector<int> ids, low;
    std::vector<bool> onStack;
    std::stack<int> stack;
    int id, sccCount;

    void dfs(int at) {
        stack.push(at);
        onStack[at] = true;
        ids[at] = low[at] = id++;

        for (int to : graph[at]) {
            if (ids[to] == -1) {
                dfs(to);
                low[at] = std::min(low[at], low[to]);
            } else if (onStack[to]) {
                low[at] = std::min(low[at], ids[to]);
            }
        }

        if (ids[at] == low[at]) {
            while (true) {
                int node = stack.top();
                stack.pop();
                onStack[node] = false;
                low[node] = ids[at];
                if (node == at) break;
            }
            sccCount++;
        }
    }

public:
    TarjanSCC(int n) : n(n), graph(n), ids(n, -1), low(n, -1), onStack(n, false), id(0), sccCount(0) {}

    void addEdge(int from, int to) {
        graph[from].push_back(to);
    }

    std::vector<std::vector<int>> findSCCs() {
        for (int i = 0; i < n; i++) {
            if (ids[i] == -1) {
                dfs(i);
            }
        }

        std::vector<std::vector<int>> sccs(sccCount);
        for (int i = 0; i < n; i++) {
            sccs[low[i]].push_back(i);
        }

        return sccs;
    }
};

#endif // INCLUDED_UTILITIES_TARJAN_HPP
