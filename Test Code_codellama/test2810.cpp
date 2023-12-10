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

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        Node* current = root;
        if (current == nullptr) {
            root = new Node(value);
            return;
        }

        while (true) {
            if (value < current->value) {
                if (current->left == nullptr) {
                    current->left = new Node(value);
                    return;
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = new Node(value);
                    return;
                }
                current = current->right;
            }
        }
    }

    void inOrderTraversal() {
        Node* current = root;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->left;
        }
    }
};
