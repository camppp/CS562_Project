vector<int> updateVa(const vector<int>& sa, const vector<int>& pos) {
    vector<int> va(sa.size());
    for (int i = 0; i < sa.size(); i++) {
        va[i] = sa[i] + pos[i];
    }
    return va;
}
