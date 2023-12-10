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

    // Private helper method to recursively construct the binary tree
    Node* constructTreeHelper(const std::vector<int>& values, int index) {
        if (index < values.size()) {
            Node* newNode = new Node(values[index]);
            newNode->left = constructTreeHelper(values, 2 * index + 1);
            newNode->right = constructTreeHelper(values, 2 * index + 2);
            return newNode;
        }
        return nullptr;
    }

public:
    // Public method to construct the binary tree from a vector of values
    void constructTree(const std::vector<int>& values) {
        root = constructTreeHelper(values, 0);
    }

    // Overload the type conversion operator to return the value of the root node
    operator unsigned int() {
        return root->value;
    }
};

int main() {
    BinaryTree tree;
    tree.constructTree({1, 2, 3, 4, 5, 6, 7});

    unsigned int rootValue = tree; // Implicit conversion to unsigned int
    std::cout << "Root value: " << rootValue << std::endl;

    return 0;
}
