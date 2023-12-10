bool areLeafValuesSame(TreeNode* root1, TreeNode* root2) {
    std::vector<int> leafValues1 = getLeafValue(root1);
    std::vector<int> leafValues2 = getLeafValue(root2);

    if (leafValues1.size() != leafValues2.size()) {
        return false;
    }

    for (int i = 0; i < leafValues1.size(); i++) {
        if (leafValues1[i] != leafValues2[i]) {
            return false;
        }
    }

    return true;
}
