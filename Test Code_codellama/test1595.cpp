int BigInt::compare(const BigInt& x) const {
    int n = b.size();
    int m = x.b.size();
    int i = 0;
    while (i < n && i < m) {
        if (b[i] != x.b[i]) {
            return b[i] > x.b[i] ? 1 : -1;
        }
        i++;
    }
    if (i < n) {
        return 1;
    } else if (i < m) {
        return -1;
    } else {
        return 0;
    }
}
