int KthSmallestElement(Node *root, int &K) {
    if (root == nullptr || K < 1) {
        return -1;
    }

    // Find the smallest element in the left subtree
    int leftSmallest = KthSmallestElement(root->left, K);
    if (leftSmallest != -1) {
        return leftSmallest;
    }

    // If the smallest element in the left subtree is not found,
    // then the current node must be the Kth smallest element
    if (K == 1) {
        return root->data;
    }

    // Decrement K and find the smallest element in the right subtree
    K--;
    int rightSmallest = KthSmallestElement(root->right, K);
    if (rightSmallest != -1) {
        return rightSmallest;
    }

    return -1;
}
