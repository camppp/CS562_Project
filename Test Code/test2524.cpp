#include <iostream>

using namespace std;

struct Splay {
  // ... (same as in the problem description)

  // ... (same as in the problem description)

  void insert(int val) {
    if (!root) {
      root = new Node(val);
      return;
    }
    Node* cur = root;
    Node* par = nullptr;
    while (cur) {
      par = cur;
      if (val < cur->val) {
        cur = cur->child[0];
      } else if (val > cur->val) {
        cur = cur->child[1];
      } else {
        // Value already exists in the tree
        return;
      }
    }
    cur = new Node(val);
    cur->par = par;
    if (val < par->val) {
      par->child[0] = cur;
    } else {
      par->child[1] = cur;
    }
    splay(cur);
  }

  Splay::Node* find(int val) {
    Node* cur = root;
    while (cur) {
      if (val < cur->val) {
        cur = cur->child[0];
      } else if (val > cur->val) {
        cur = cur->child[1];
      } else {
        splay(cur);
        return cur;
      }
    }
    return nullptr;
  }
};

int main() {
  Splay tree;
  tree.insert(5);
  tree.insert(8);
  tree.insert(3);
  tree.insert(12);
  tree.insert(9);
  tree.insert(1);

  Splay::Node* found = tree.find(8);
  if (found) {
    cout << "Node with value 8 found and splayed to the root." << endl;
  } else {
    cout << "Node with value 8 not found." << endl;
  }

  return 0;
}
