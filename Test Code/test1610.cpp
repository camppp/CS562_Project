// Given class and methods
template <typename T>
class binary_indexed_tree {
  std::vector<T> dat;
  T merge(T a, T b) const { return a + b; }
  // ... other constructors and methods

public:
  binary_indexed_tree(size_t N) : dat(N + 1, NEUTRAL) {}
  binary_indexed_tree(size_t N, T t) : dat(N + 1, NEUTRAL) {
    for (int i = 0; i < (int)N; ++i) {
      update(i, t);
    }
  }

  // Your completed methods
  void update(int idx, T val) {
    idx++;
    while (idx < dat.size()) {
      dat[idx] = merge(dat[idx], val);
      idx += idx & -idx;
    }
  }

  T query(int idx) const {
    T res = NEUTRAL;
    while (idx > 0) {
      res = merge(res, dat[idx]);
      idx -= idx & -idx;
    }
    return res;
  }
};
