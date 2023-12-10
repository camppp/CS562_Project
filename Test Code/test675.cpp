#include <vector>
using namespace std;

class Solution {
public:
    int countDistinctPaths(vector<vector<int>>& graph, int cur) {
        int pathCount = 0;
        vector<bool> visited(graph.size(), false);
        dfs(graph, cur, visited, pathCount);
        return pathCount;
    }

    void dfs(vector<vector<int>>& graph, int cur, vector<bool>& visited, int& pathCount) {
        visited[cur] = true;
        for (int i = 0; i < graph[cur].size(); i++) {
            int nextNode = graph[cur][i];
            if (!visited[nextNode]) {
                pathCount++;
                dfs(graph, nextNode, visited, pathCount);
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {3}, {4}, {}};
    int startNode = 0;
    int result = solution.countDistinctPaths(graph, startNode);
    // Output the result
    return 0;
}
