int lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    int start = 0;
    int end = 0;
    unordered_set<char> charSet;

    while (end < s.length()) {
        char c = s[end];
        if (charSet.find(c) == charSet.end()) {
            charSet.insert(c);
            maxLength = max(maxLength, end - start + 1);
        } else {
            start = charSet.find(c) + 1;
            charSet.erase(charSet.find(c));
        }
        end++;
    }

    return maxLength;
}
