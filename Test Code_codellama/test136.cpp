bool isEqual(const Collection& col) {
    if (items.size() != col.items.size()) {
        return false;
    }

    for (int i = 0, n = items.size(); i < n; ++i) {
        if (items[i] != col.items[i]) {
            return false;
        }
    }

    return true;
}
