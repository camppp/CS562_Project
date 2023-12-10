++
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> nodesAtDistanceK(TreeNode* root, int target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent; // Map to store parent of each node
    queue<TreeNode*> q; // Queue for BFS traversal
    unordered_map<TreeNode*, bool> visited; // Map to mark visited nodes
    vector<int> result; // Vector to store nodes at distance k

    // Perform BFS to populate the parent map and find the target node
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left) {
            parent[node->left] = node;
            q.push(node->left);
        }
        if (node->right) {
            parent[node->right] = node;
            q.push(node->right);
        }
        if (node->val == target) {
            break;
        }
    }

    // Perform BFS starting from the target node to find nodes at distance k
    q.push(parent[target]);
    visited[parent[target]] = true;
    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (level == k) {
                result.push_back(node->val);
            }
            if (node->left && !visited[node->left]) {
                q.push(node->left);
                visited[node->left] = true;
            }
            if (node->right && !visited[node->right]) {
                q.push(node->right);
                visited[node->right] = true;
            }
            if (parent[node] && !visited[parent[node]]) {
                q.push(parent[node]);
                visited[parent[node]] = true;
            }
        }
        level++;
        if (level > k) {
            break;
        }
    }

    return result;
}
