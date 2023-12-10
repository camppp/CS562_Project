#include <vector>
#include <algorithm>

struct Edge {
  int node;
  int weight;
};

std::vector<std::vector<Edge>> tree;
std::vector<bool> vis;

void dfs(int node) {
  vis[node] = true;
  for (const Edge& edge : tree[node]) {
    if (!vis[edge.node]) {
      dfs(edge.node);
    }
  }
}

double maxSumOfNonAdjacentNodes(int n, std::vector<std::vector<Edge>> tree) {
  ::tree = tree;
  vis.assign(n + 1, false);
  int root = (1 << n) - 1;
  memset(vis.data(), 0, sizeof(bool) * (n + 1));
  dfs(root);

  double ans = -1;
  for (int i = 0; i < tree[root].size(); i++) {
    ans = std::max(ans, static_cast<double>(tree[root][i].weight));
  }
  return ans;
}
