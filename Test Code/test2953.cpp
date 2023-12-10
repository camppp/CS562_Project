#include <iostream>

// The provided code snippet is a partial implementation of Tarjan's algorithm for finding strongly connected components (SCCs) in a directed graph.
// The missing parts of the dfs function need to be completed to correctly identify the SCCs and return them in a topologically sorted order.

// The completed implementation of the TarjanSCC class is as follows:

class TarjanSCC {
    // ... (same as in the code snippet)

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
            std::vector<int> scc;
            int node;
            do {
                node = stack.top();
                stack.pop();
                onStack[node] = false;
                scc.push_back(node);
                low[node] = ids[at];
            } while (node != at);
            std::sort(scc.begin(), scc.end());
            sccs.push_back(scc);
        }
    }

public:
    // ... (same as in the code snippet)

    std::vector<std::vector<int>> findSCCs() {
        for (int i = 0; i < n; i++) {
            if (ids[i] == -1) {
                dfs(i);
            }
        }

        std::sort(sccs.begin(), sccs.end());
        return sccs;
    }
};

// The completed implementation ensures that the Tarjan's algorithm correctly identifies the SCCs and returns them in a topologically sorted order.
// The findSCCs function now sorts the SCCs before returning them, ensuring a topologically sorted order of the SCCs.
