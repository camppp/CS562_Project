bool isValidBST(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }

    // Check if the left subtree is a valid BST
    if (root->left != nullptr && root->left->val >= root->val) {
        return false;
    }

    // Check if the right subtree is a valid BST
    if (root->right != nullptr && root->right->val <= root->val) {
        return false;
    }

    // Recursively check the left and right subtrees
    return isValidBST(root->left) && isValidBST(root->right);
}
