#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> levelOrderBottom(TreeNode *root) {
    if (root == nullptr) {
        return {};
    }

    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> levelValues;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            levelValues.push_back(node->val);

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }

        result.push_back(levelValues);
    }

    reverse(result.begin(), result.end());
    return result;
}
