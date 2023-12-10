int calculateSize(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftSize = calculateSize(root->left);
    int rightSize = calculateSize(root->right);

    return leftSize + rightSize + 1;
}
