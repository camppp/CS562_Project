TreeNode* buildTree(std::vector<int>& nums, int begin, int end) {
    if (begin > end) return nullptr;
    
    int mid = (begin + end) / 2;
    
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = buildTree(nums, begin, mid - 1);
    node->right = buildTree(nums, mid + 1, end);
    
    return node;
}
