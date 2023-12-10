bool canDivideDeck(vector<int>& deck) {
    int n = deck.size();
    int k = n / 2;
    if (n % 2 == 1) {
        return false;
    }
    unordered_map<int, int> counts;
    for (int i = 0; i < n; i++) {
        counts[deck[i]]++;
    }
    for (auto it = counts.begin(); it != counts.end(); it++) {
        if (it->second != k) {
            return false;
        }
    }
    return true;
}
