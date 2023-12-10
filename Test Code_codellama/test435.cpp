struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDiffInBST(TreeNode* root) {
    int minDiff = INT_MAX;
    int prev = INT_MIN;
    inorderTraversal(root, prev, minDiff);
    return minDiff;
}

void inorderTraversal(TreeNode* root, int& prev, int& minDiff) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left, prev, minDiff);
    if (prev != INT_MIN) {
        minDiff = min(minDiff, abs(prev - root->val));
    }
    prev = root->val;
    inorderTraversal(root->right, prev, minDiff);
}
