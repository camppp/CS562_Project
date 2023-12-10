string addStrings(string s1, string s2) {
    string f;
    int carry = 0;
    for (int i = 0; i < s1.size(); i++) {
        int sum = s1[i] - '0' + s2[i] - '0' + carry;
        f.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    for (int i = s1.size(); i < s2.size(); i++) {
        int sum = s2[i] - '0' + carry;
        f.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry > 0) {
        f.push_back(carry + '0');
    }
    return f;
}
