int findUniqueElement(vector<int>& arr) {
    unordered_set<int> seen;
    for (int i = 0; i < arr.size(); i++) {
        if (seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]);
        } else {
            seen.erase(arr[i]);
        }
    }
    return *seen.begin();
}
