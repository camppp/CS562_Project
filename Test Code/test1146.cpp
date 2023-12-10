#include <vector>
using namespace std;

class Solution {
public:
    int countReachableNodes(vector<vector<int>>& adjList, int u) {
        vector<bool> visited(adjList.size(), false);
        return DFS(adjList, u, visited);
    }

    int DFS(vector<vector<int>>& adjList, int u, vector<bool>& visited) {
        int ans = 1;  // Count the current node
        visited[u] = true;
        for (int e : adjList[u]) {
            if (!visited[e]) {
                ans += DFS(adjList, e, visited);
            }
        }
        return ans;
    }
};
