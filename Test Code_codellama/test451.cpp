string sum(string a, string b) {
    string result;
    int carry = 0;
    for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';
        }
        if (j >= 0) {
            sum += b[j] - '0';
        }
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry > 0) {
        result.push_back(carry + '0');
    }
    reverse(result.begin(), result.end());
    return result;
}
