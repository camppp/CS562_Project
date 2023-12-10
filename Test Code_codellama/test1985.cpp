std::vector<int> shortestToChar(std::string &s, char c) {
    std::vector<int> result;
    int left = 0, right = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c) {
            left = i;
        }
        result.push_back(std::min(left - i, right - i));
    }
    return result;
}
