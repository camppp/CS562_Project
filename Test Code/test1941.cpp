#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1)
        return t2;
    if (!t2)
        return t1;

    TreeNode *node = new TreeNode(t1->val + t2->val);
    node->left = mergeTrees(t1->left, t2->left);
    node->right = mergeTrees(t1->right, t2->right);

    return node;
}

int main() {
    // Example usage
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(5);

    TreeNode* t2 = new TreeNode(2);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(3);
    t2->left->right = new TreeNode(4);
    t2->right->right = new TreeNode(7);

    TreeNode* merged = mergeTrees(t1, t2);
    // Output the merged tree or perform any other operations
    return 0;
}
