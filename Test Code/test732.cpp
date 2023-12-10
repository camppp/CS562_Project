int max(int a, int b) {
    return (a > b) ? a : b;
}

int calculateHeight(struct Node* root) {
    if (root == NULL) {
        return -1;  // Height of an empty tree is -1
    } else {
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
}
