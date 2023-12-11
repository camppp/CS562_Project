int shortestRepeatingSubstringLength(String s) {
    int n = s.length();
    int minLength = INT_MAX;
    for (int i = 0; i < n; i++) {
        int length = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == s[i]) {
                length++;
            } else {
                break;
            }
        }
        if (length < minLength) {
            minLength = length;
        }
    }
    return minLength;
}
