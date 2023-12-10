#include <iostream>
#include <vector>

template <typename T>
struct Monoid {
  T identity;
  T operator()(const T &a, const T &b) const { return a + b; }
};

template <typename T>
struct WeightBalancedTree {
  struct Node {
    T value;
    int weight;
    Node *left, *right;
  };

  Node *root;
  // Other necessary members and methods

  // Method to insert a new node into the WBT
  void insert(Node *&r, const T &value) {
    if (r == nullptr) {
      r = new Node{value, 1, nullptr, nullptr};
    } else if (value < r->value) {
      insert(r->left, value);
    } else {
      insert(r->right, value);
    }
    balance(r);
  }

  // Method to remove a node from the WBT
  void remove(Node *&r, const T &value) {
    if (r == nullptr) return;
    if (value < r->value) {
      remove(r->left, value);
    } else if (value > r->value) {
      remove(r->right, value);
    } else {
      if (r->left == nullptr) {
        Node *temp = r->right;
        delete r;
        r = temp;
      } else if (r->right == nullptr) {
        Node *temp = r->left;
        delete r;
        r = temp;
      } else {
        Node *temp = findMin(r->right);
        r->value = temp->value;
        r->weight = temp->weight;
        remove(r->right, temp->value);
      }
    }
    balance(r);
  }

  // Method to find the node with the minimum value in the WBT
  Node *findMin(Node *r) {
    while (r->left != nullptr) {
      r = r->left;
    }
    return r;
  }

  // Method to balance the WBT after insertion or deletion
  void balance(Node *&r) {
    if (r == nullptr) return;
    int leftWeight = r->left == nullptr ? 0 : r->left->weight;
    int rightWeight = r->right == nullptr ? 0 : r->right->weight;

    if (leftWeight > 3 * rightWeight || rightWeight > 3 * leftWeight) {
      std::vector<T> values;
      collect(r, values);
      r = build(values, 0, values.size());
    } else {
      r->weight = leftWeight + rightWeight + 1;
    }
  }

  // Method to collect the values of the WBT in sorted order
  void collect(Node *r, std::vector<T> &values) {
    if (r == nullptr) return;
    collect(r->left, values);
    values.push_back(r->value);
    collect(r->right, values);
  }

  // Method to build a balanced WBT from a sorted array of values
  Node *build(const std::vector<T> &values, int start, int end) {
    if (start >= end) return nullptr;
    int mid = (start + end) / 2;
    Node *r = new Node{values[mid], 1, nullptr, nullptr};
    r->left = build(values, start, mid);
    r->right = build(values, mid + 1, end);
    r->weight = (r->left == nullptr ? 0 : r->left->weight) +
                (r->right == nullptr ? 0 : r->right->weight) + 1;
    return r;
  }

  // Method to query the size of the WBT
  int size(Node *r) {
    return r == nullptr ? 0 : r->weight;
  }

  // Method to query the sum of values within a specified range in the WBT
  T querySum(Node *r, const T &low, const T &high) {
    if (r == nullptr) return T();
    if (r->value < low) {
      return querySum(r->right, low, high);
    } else if (r->value > high) {
      return querySum(r->left, low, high);
    } else {
      return r->value + querySum(r->left, low, r->value) +
             querySum(r->right, r->value, high);
    }
  }
};

int main() {
  WeightBalancedTree<int> wbt;
  wbt.insert(wbt.root, 5);
  wbt.insert(wbt.root, 3);
  wbt.insert(wbt.root, 7);
  wbt.insert(wbt.root, 2);
  wbt.insert(wbt.root, 4);
  wbt.insert(wbt.root, 6);
  wbt.insert(wbt.root, 8);

  std::cout << "Size of the WBT: " << wbt.size(wbt.root) << std::endl;
  std::cout << "Sum of values in range [3, 7]: "
            << wbt.querySum(wbt.root, 3, 7) << std::endl;

  wbt.remove(wbt.root, 5);
  std::cout << "Size of the WBT after removing 5: " << wbt.size(wbt.root)
            << std::endl;

  return 0;
}
