bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, nullptr, nullptr);
}

bool isValidBSTHelper(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
    if (node == nullptr) {
        return true;
    }
    
    if ((minNode != nullptr && node->val <= minNode->val) || (maxNode != nullptr && node->val >= maxNode->val)) {
        return false;
    }
    
    return isValidBSTHelper(node->left, minNode, node) && isValidBSTHelper(node->right, node, maxNode);
}
