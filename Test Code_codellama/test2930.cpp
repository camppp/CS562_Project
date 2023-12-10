class SegmentTree {
public:
    SegmentTree(int n) {
        // Initialize the segment tree with n nodes
        tree = new Node[n];
        for (int i = 0; i < n; i++) {
            tree[i].left = i * 2 + 1;
            tree[i].right = i * 2 + 2;
            tree[i].sum = 0;
        }
    }

    void build(int n, int arr[]) {
        // Build the segment tree from the given array
        for (int i = n - 1; i >= 0; i--) {
            tree[i].sum = arr[i];
            if (i * 2 + 1 < n) {
                tree[i].left = build(i * 2 + 1, arr);
            }
            if (i * 2 + 2 < n) {
                tree[i].right = build(i * 2 + 2, arr);
            }
        }
    }

    int rangeQuery(int l, int r) {
        // Perform a range query on the segment tree
        int result = 0;
        for (int i = l; i <= r; i++) {
            result += tree[i].sum;
        }
        return result;
    }

private:
    struct Node {
        int left;
        int right;
        int sum;
    };
    Node* tree;
};
