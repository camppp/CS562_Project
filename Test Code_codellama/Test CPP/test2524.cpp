#include <iostream>

using namespace std;

struct Splay {
  struct Node {
    int val, sz;
    Node *child[2], *par;
    Node() {}
    Node(int val, int sz = 1) : val(val), sz(sz) {
      child[0] = child[1] = par = nullptr;
    }
  };

  Node* root;

  Splay() : root(nullptr) {}

  void rotate(Node* x, int c) {
    Node* y = x->child[c];
    x->child[c] = y->child[!c];
    if (y->child[!c]) y->child[!c]->par = x;
    y->par = x->par;
    if (!x->par) root = y;
    else if (x == x->par->child[!c]) x->par->child[!c] = y;
    else x->par->child[c] = y;
    y->child[!c] = x;
    x->par = y;
    if (x) x->sz = (x->child[0] ? x->child[0]->sz : 0) + (x->child[1] ? x->child[1]->sz : 0) + 1;
    if (y) y->sz = (y->child[0] ? y->child[0]->sz : 0) + (y->child[1] ? y->child[1]->sz : 0) + 1;
  }

  void splay(Node* x) {
    while (x->par) {
      if (!x->par->par) {
        rotate(x->par, x->par->child[0] == x);
      } else {
        int c = x->par->par->child[0] == x->par;
        if (x->par->child[c] == x) {
          rotate(x->par->par, !c);
          rotate(x->par, !c);
        } else {
          rotate(x->par, c);
          rotate(x->par, !c);
        }
      }
    }
  }

  void insert(int val) {
    Node* x = root;
    Node* y = nullptr;
    while (x) {
      y = x;
      if (val < x->val) {
        x = x->child[0];
      } else if (val > x->val) {
        x = x->child[1];
      } else {
        return;
      }
    }
    Node* z = new Node(val);
    z->par = y;
    if (y) {
      if (val < y->val) {
        y->child[0] = z;
      } else {
        y->child[1] = z;
      }
    } else {
      root = z;
    }
    splay(z);
  }

  Node* find(int val) {
    Node* x = root;
    while (x) {
      if (val < x->val) {
        x = x->child[0];
      } else if (val > x->val) {
        x = x->child[1];
      } else {
        splay(x);
        return x;
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
