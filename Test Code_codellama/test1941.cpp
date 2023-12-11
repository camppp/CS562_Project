TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL) {
        return t2;
    }
    if (t2 == NULL) {
        return t1;
    }
    TreeNode* root = new TreeNode(t1->val + t2->val);
    root->left = mergeTrees(t1->left, t2->left);
    root->right = mergeTrees(t1->right, t2->right);
    return root;
}