class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        while (root != nullptr) {
            if (root->left != nullptr) {
                TreeNode* rightmost = root->left;
                while (rightmost->right != nullptr) {
                    rightmost = rightmost->right;
                }
                rightmost->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
}
