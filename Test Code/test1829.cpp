vector<string> addOperators(string num, int target) {
    vector<string> result;
    int n = num.size();
    for (int i = 0; i < n; i++) {
        int cur = stoi(num.substr(0, i + 1));
        if (cur == target) {
            result.push_back(num.substr(0, i + 1));
        }
        for (int j = i + 1; j < n; j++) {
            int left = stoi(num.substr(0, i + 1));
            int right = stoi(num.substr(i + 1, j - i));
            int sum = left + right;
            if (sum == target) {
                result.push_back(num.substr(0, i + 1) + "+" + num.substr(i + 1, j - i));
            }
            sum = left - right;
            if (sum == target) {
                result.push_back(num.substr(0, i + 1) + "-" + num.substr(i + 1, j - i));
            }
            sum = left * right;
            if (sum == target) {
                result.push_back(num.substr(0, i + 1) + "*" + num.substr(i + 1, j - i));
            }
        }
    }
    return result;
}
