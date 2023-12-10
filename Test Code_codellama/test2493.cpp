#include <iostream>

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

// Binary tree data structure
struct BinaryTree {
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    // Insert a new node into the binary tree
    void Insert(int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
        } else {
            TreeNode* current = root;
            while (current != nullptr) {
                if (value < current->value) {
                    if (current->left == nullptr) {
                        current->left = new TreeNode(value);
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == nullptr) {
                        current->right = new TreeNode(value);
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }

    // Print the binary tree in order
    void Print() {
        if (root != nullptr) {
            Print(root);
        }
    }

    // Recursive function to print the binary tree in order
    void Print(TreeNode* current) {
        if (current->left != nullptr) {
            Print(current->left);
        }
        std::cout << current->value << " ";
        if (current->right != nullptr) {
            Print(current->right);
        }
    }

    // Layout the binary tree based on the layout parameter
    void Layout(int layoutParam) {
        if (root != nullptr) {
            root->Layout(layoutParam);
        }
    }
};

int main() {
    // Create a binary tree
    BinaryTree tree;

    // Insert some nodes into the binary tree
    tree.Insert(10);
    tree.Insert(5);
    tree.Insert(15);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(12);

    // Print the binary tree in order
    tree.Print();

    // Layout the binary tree based on the layout parameter
    tree.Layout(10);

    // Print the binary tree in order again
    tree.Print();

    return 0;
}
