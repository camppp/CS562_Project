c
vector<int> nodesAtDistanceK(TreeNode* root, int target, int k) {
    vector<int> result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node->val == target) {
            if (k == 0) {
                result.push_back(node->val);
            } else {
                q.push(node->left);
                q.push(node->right);
            }
        } else if (k > 0) {
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }
    return result;
}
