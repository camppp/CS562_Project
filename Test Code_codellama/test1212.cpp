int kthSmallest(Node* root, int k) {
    if (root == nullptr) {
        return -1;
    }

    // Find the number of nodes in the left subtree
    int leftSize = countNodes(root->left);

    // If k is less than the number of nodes in the left subtree,
    // the k-th smallest element is in the left subtree
    if (k <= leftSize) {
        return kthSmallest(root->left, k);
    }

    // If k is greater than the number of nodes in the left subtree,
    // the k-th smallest element is in the right subtree
    else {
        return kthSmallest(root->right, k - leftSize - 1);
    }
}

int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}
