#include <vector>
#include <algorithm>

bool canFormTreePair(std::vector<int> tree, int k) {
    std::sort(tree.begin(), tree.end()); // Sort the tree positions in ascending order

    int i = 0, j = tree.size() - 1;
    while (i < j) {
        if (tree[i] + k < tree[j]) {
            i++; // Move to the next tree position from the left
        } else if (tree[i] + k > tree[j]) {
            j--; // Move to the next tree position from the right
        } else {
            return true; // Found two trees with distance k
        }
    }
    return false; // No such pair of trees found
}
