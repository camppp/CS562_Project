#include <vector>
#include <unordered_map>

class DisjointSet {
private:
    std::unordered_map<value_type, value_type> parent_;
    std::unordered_map<value_type, std::size_t> size_;

public:
    void makeSet(value_type x) {
        parent_[x] = x;
        size_[x] = 1;
    }

    value_type find(value_type x) {
        if (parent_[x] != x) {
            parent_[x] = find(parent_[x]);
        }
        return parent_[x];
    }

    void merge(value_type x, value_type y) {
        value_type rootX = find(x);
        value_type rootY = find(y);
        if (rootX != rootY) {
            if (size_[rootX] < size_[rootY]) {
                std::swap(rootX, rootY);
            }
            parent_[rootY] = rootX;
            size_[rootX] += size_[rootY];
        }
    }

    std::size_t largestSetSize() {
        std::size_t maxSize = 0;
        for (const auto& pair : size_) {
            maxSize = std::max(maxSize, pair.second);
        }
        return maxSize;
    }
};

std::size_t largestSetSize(const std::vector<std::pair<value_type, value_type>>& mergeOperations) {
    DisjointSet ds;
    for (const auto& mergeOp : mergeOperations) {
        ds.makeSet(mergeOp.first);
        ds.makeSet(mergeOp.second);
        ds.merge(mergeOp.first, mergeOp.second);
    }
    return ds.largestSetSize();
}
