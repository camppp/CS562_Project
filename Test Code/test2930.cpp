#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class SegmentTree {
private:
    vector<T> tree;
    int n;

    void buildTree(const vector<T>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            buildTree(arr, v*2, tl, tm);
            buildTree(arr, v*2+1, tm+1, tr);
            tree[v] = max(tree[v*2], tree[v*2+1]);  // Change max to min or sum for different operations
        }
    }

    T rangeQuery(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return numeric_limits<T>::min();  // Change min to max or 0 for different operations
        }
        if (l == tl && r == tr) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return max(rangeQuery(v*2, tl, tm, l, min(r, tm)), rangeQuery(v*2+1, tm+1, tr, max(l, tm+1), r));  // Change max to min or + for different operations
    }

public:
    SegmentTree(const vector<T>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 1, 0, n-1);
    }

    T rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n-1, l, r);
    }
};

int main() {
    vector<int> src = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    SegmentTree<int> maxTree(src);

    int l = 0, devSize = 3;
    vector<int> result;
    for (l = 0; l < devSize; l++) {
        int begin, end;
        cin >> begin >> end;
        result.push_back(maxTree.rangeQuery(begin, end));
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
