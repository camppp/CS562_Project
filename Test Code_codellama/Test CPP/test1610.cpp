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
