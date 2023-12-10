int treeDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
        return 1 + std::max(leftDepth, rightDepth);
    }
}
