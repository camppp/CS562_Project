void elimDups(vector<string>& v) {
    sort(v.begin(), v.end(), isShorter);
    v.erase(unique(v.begin(), v.end()), v.end());
}
