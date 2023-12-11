int treeDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftDepth = treeDepth(root->left);
    int rightDepth = treeDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}
