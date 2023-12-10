int ans = 0;
int lb, hb;

void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    if (root->val >= lb && root->val <= hb) {
        ans += root->val;
    }
    inorder(root->right);
}

int rangeSumBST(TreeNode* root, int low, int high) {
    lb = low;
    hb = high;
    inorder(root);
    return ans;
}
