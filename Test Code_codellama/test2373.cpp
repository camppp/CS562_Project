#include <iostream>
#include <vector>

// Node structure for the WBT
struct Node {
  int key;
  int value;
  int weight;
  Node* left;
  Node* right;

  Node(int key, int value, int weight) : key(key), value(value), weight(weight), left(nullptr), right(nullptr) {}
};

// WBT class
class WBT {
public:
  // Constructor
  WBT() : root(nullptr) {}

  // Destructor
  ~WBT() {
    delete root;
  }

  // Insert a new node into the WBT
  void insert(int key, int value) {
    // Create a new node with the given key and value
    Node* newNode = new Node(key, value, 1);

    // If the root node is null, set the new node as the root
    if (root == nullptr) {
      root = newNode;
    } else {
      // Find the appropriate position for the new node
      Node* current = root;
      while (current != nullptr) {
        if (key < current->key) {
          if (current->left == nullptr) {
            current->left = newNode;
            break;
          } else {
            current = current->left;
          }
        } else if (key > current->key) {
          if (current->right == nullptr) {
            current->right = newNode;
            break;
          } else {
            current = current->right;
          }
        } else {
          // Key already exists, do nothing
          break;
        }
      }
    }

    // Rebalance the tree if necessary
    rebalance();
  }

  // Remove a node from the WBT
  void remove(int key) {
    // Find the node to remove
    Node* current = root;
    while (current != nullptr) {
      if (key < current->key) {
        current = current->left;
      } else if (key > current->key) {
        current = current->right;
      } else {
        // Found the node to remove
        break;
      }
    }

    // If the node to remove is found, remove it
    if (current != nullptr) {
      // If the node to remove has no children, remove it
      if (current->left == nullptr && current->right == nullptr) {
        if (current == root) {
          root = nullptr;
        } else {
          Node* parent = current->parent;
          if (parent->left == current) {
            parent->left = nullptr;
          } else {
            parent->right = nullptr;
          }
        }
        delete current;
      } else {
        // If the node to remove has children, replace it with its successor
        Node* successor = current->right;
        while (successor->left != nullptr) {
          successor = successor->left;
        }
        current->key = successor->key;
        current->value = successor->value;
        current->weight = successor->weight;
        successor->parent = current->parent;
        if (successor->parent->left == current) {
          successor->parent->left = successor;
        } else {
          successor->parent->right = successor;
        }
        delete current;
      }
    }

    // Rebalance the tree if necessary
    rebalance();
  }

  // Retrieve the size of the WBT
  int size() {
    return size(root);
  }

  // Retrieve the sum of values within a specified range in the WBT
  int querySum(int start, int end) {
    // Find the range of nodes to sum
    Node* current = root;
    while (current != nullptr) {
      if (current->key < start) {
        current = current->right;
      } else if (current->key > end) {
        current = current->left;
      } else {
        // Found the range, sum the values
        int sum = 0;
        while (current != nullptr) {
          sum += current->value;
          current = current->left;
        }
        return sum;
      }
    }
    return 0;
  }

private:
  // Rebalance the tree if necessary
  void rebalance() {
    // If the tree is unbalanced, rebalance it
    if (isUnbalanced(root)) {
      root = rebalance(root);
    }
  }

  // Check if the tree is unbalanced
  bool isUnbalanced(Node* node) {
    // If the tree is empty, it is not unbalanced
    if (node == nullptr) {
      return false;
    }

    // If the tree is not empty, check if it is unbalanced
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    if (abs(leftHeight - rightHeight) > 1) {
      return true;
    }

    // If the tree is not unbalanced, check if its children are unbalanced
    return isUnbalanced(node->left) || isUnbalanced(node->right);
  }

  // Rebalance the tree
  Node* rebalance(Node* node) {
    // If the tree is empty, return nullptr
    if (node == nullptr) {
      return nullptr;
    }

    // If the tree is not empty, rebalance it
    Node* left = rebalance(node->left);
    Node* right = rebalance(node->right);
    int leftHeight = height(left);
    int rightHeight = height(right);
    if (abs(leftHeight - rightHeight) > 1) {
      // If the tree is unbalanced, rotate it
      if (leftHeight > rightHeight) {
        // Left-left rotation
        Node* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        return newRoot;
      } else {
        // Right-right rotation
        Node* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        return newRoot;
      }
    }

    // If the tree is not unbalanced, return it
    return node;
  }

  // Retrieve the height of a node
  int height(Node* node) {
    // If the node is nullptr, return 0
    if (node == nullptr) {
      return 0;
    }

    // If the node is not nullptr, return its height
    return 1 + std::max(height(node->left), height(node->right));
  }

  // Retrieve the size of a node
  int size(Node* node) {
    // If the node is nullptr, return 0
    if (node == nullptr) {
      return 0;
    }

    // If the node is not nullptr, return its size
    return 1 + size(node->left) + size(node->right);
  }

  // The root node of the WBT
  Node* root;
};
