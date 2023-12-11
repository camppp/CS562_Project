#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int rangeSumBST(TreeNode* root, int low, int high) {
    if (root == nullptr) {
        return 0;
    }

    // If the current node value is within the range, include it in the sum
    int sum = (root->val >= low && root->val <= high) ? root->val : 0;

    // Recursively search the left and right subtrees
    sum += rangeSumBST(root->left, low, high);
    sum += rangeSumBST(root->right, low, high);

    return sum;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    int low = 7;
    int high = 15;

    int result = rangeSumBST(root, low, high);

    std::cout << "Sum of values in the range [" << low << ", " << high << "]: " << result << std::endl;

    // Clean up memory (not shown in the original code snippet)
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
