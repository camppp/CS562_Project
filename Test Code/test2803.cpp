#include <utility>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

pair<TreeNode*, TreeNode*> convert(TreeNode* root) {
    if (root == nullptr) {
        return {nullptr, nullptr};
    }

    if (root->left != nullptr) {
        pair<TreeNode*, TreeNode*> leftPart = convert(root->left);
        root->left = nullptr;
        root->right = leftPart.first;
        if (leftPart.second != nullptr) {
            return {root, leftPart.second};
        }
    }

    if (root->right != nullptr) {
        pair<TreeNode*, TreeNode*> rightPart = convert(root->right);
        root->right = rightPart.first;
        return {root, rightPart.second};
    }

    return {root, root};
}
