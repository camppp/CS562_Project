class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    int maxPathSum(TreeNode* root) {
        int vmax = INT_MIN;
        maxPathSumHelper(root, vmax);
        return vmax;
    }

    int maxPathSumHelper(TreeNode* node, int& vmax) {
        if (node == nullptr) {
            return 0;
        }

        int left = max(0, maxPathSumHelper(node->left, vmax));
        int right = max(0, maxPathSumHelper(node->right, vmax));

        vmax = max(vmax, node->val + left + right);

        return node->val + max(left, right);
    }
};
