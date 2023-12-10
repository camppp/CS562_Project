bool areLeafValuesSame(TreeNode* root1, TreeNode* root2) {
    auto getLeafValue = [](TreeNode* root) -> std::vector<int> {
        std::vector<int> result;
        if (root) {
            if (root->left == nullptr && root->right == nullptr) {
                result.push_back(root->val);
            } else {
                auto leftLeaves = getLeafValue(root->left);
                auto rightLeaves = getLeafValue(root->right);
                result.insert(result.end(), leftLeaves.begin(), leftLeaves.end());
                result.insert(result.end(), rightLeaves.begin(), rightLeaves.end());
            }
        }
        return result;
    };

    auto x = getLeafValue(root1);
    auto y = getLeafValue(root2);
    if (x.size() != y.size()) {
        return false;
    }
    if (x.size() == 0) {
        return true;
    }
    return std::equal(x.begin(), x.end(), y.begin(), y.end());
}
