#include <iostream>
#include <vector>
#include <set>

using namespace std;

// セグメント木のノード
struct Node {
    int l, r; // 範囲
    int c; // 色
    Node *left, *right; // 左右の子ノード
};

// セグメント木のルート
Node *root;

// セグメント木を初期化する
void init(int l, int r) {
    root = new Node();
    root->l = l;
    root->r = r;
    root->c = 0;
    root->left = NULL;
    root->right = NULL;
}

// セグメント木を更新する
void update(int x, int c) {
    Node *cur = root;
    while (cur != NULL) {
        if (x < cur->l || x > cur->r) {
            // 範囲外の場合は、子ノードに問い合わせる
            if (x < cur->l) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        } else {
            // 範囲内の場合は、色を更新する
            cur->c = c;
            break;
        }
    }
}

// セグメント木をクエリする
int query(int l, int r) {
    Node *cur = root;
    while (cur != NULL) {
        if (l < cur->l || r > cur->r) {
            // 範囲外の場合は、子ノードに問い合わせる
            if (l < cur->l) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        } else {
            // 範囲内の場合は、色を返す
            return cur->c;
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    init(1, n);
    for (int i = 1; i <= n; i++) {
        int x, c;
        cin >> x >> c;
        update(x, c);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
    return 0;
}
