string decodeString(string s) {
    string result;
    int i = 0;
    while (i < s.length()) {
        if (s[i] == '[') {
            int j = i + 1;
            while (s[j] != ']') {
                j++;
            }
            int k = stoi(s.substr(i + 1, j - i - 1));
            string substr = s.substr(j + 1, k);
            result += substr;
            i = j + k + 1;
        } else {
            result += s[i];
            i++;
        }
    }
    return result;
}
