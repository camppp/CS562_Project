int convertBase26ToDecimal(string s) {
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        result = result * 26 + (s[i] - 'A' + 1);
    }
    return result;
}
