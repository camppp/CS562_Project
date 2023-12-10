pair<TreeNode*, TreeNode*> convert(TreeNode* root) {
    if (root == nullptr) {
        return make_pair(nullptr, nullptr);
    }

    // Convert the left subtree
    auto left = convert(root->left);
    root->left = nullptr;

    // Convert the right subtree
    auto right = convert(root->right);
    root->right = nullptr;

    // Set the right child of the root to the rightmost node of the left subtree
    if (left.second != nullptr) {
        root->right = left.second;
    }

    // Set the right child of the root to the rightmost node of the right subtree
    if (right.second != nullptr) {
        root->right = right.second;
    }

    return make_pair(root, root->right);
}
