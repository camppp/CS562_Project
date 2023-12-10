// Binary tree node structure
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    int layoutSize;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr), layoutSize(0) {}

    // Layout function to set the layout size based on the layout parameter
    void Layout(int layoutParam) {
        if (left) {
            left->Layout(layoutParam);
            layoutSize = left->layoutSize;
        }
        if (right) {
            right->Layout(layoutParam);
            layoutSize = right->layoutSize;
        }
    }
};
