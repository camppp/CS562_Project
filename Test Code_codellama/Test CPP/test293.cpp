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
        if (root == nullptr) {
            root = new Node(value);
        } else {
            Node* current = root;
            while (current != nullptr) {
                if (value < current->value) {
                    if (current->left == nullptr) {
                        current->left = new Node(value);
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == nullptr) {
                        current->right = new Node(value);
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }

    unsigned int operator unsigned int() {
        return root->value;
    }
};

int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);

    unsigned int rootValue = tree; // Implicit conversion to unsigned int
    std::cout << "Root value: " << rootValue << std::endl;

    return 0;
}
