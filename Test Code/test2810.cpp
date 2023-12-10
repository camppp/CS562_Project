#include <iostream>

class BinaryTree {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;
        Node(int val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insertRecursive(Node*& current, int value) {
        if (current == nullptr) {
            current = new Node(value);
        } else if (value < current->value) {
            insertRecursive(current->left, value);
        } else {
            insertRecursive(current->right, value);
        }
    }

    void inOrderTraversalRecursive(Node* current) {
        if (current != nullptr) {
            inOrderTraversalRecursive(current->left);
            std::cout << current->value << " ";
            inOrderTraversalRecursive(current->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        insertRecursive(root, value);
    }

    void inOrderTraversal() {
        inOrderTraversalRecursive(root);
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(9);

    tree.inOrderTraversal(); // Output: 1 3 4 5 6 7 9
    return 0;
}
