string stringSum(const string& num1, const string& num2) {
    string result;
    int carry = 0;
    for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0; i--, j--) {
        int sum = carry;
        if (i >= 0) {
            sum += ctoi(num1[i]);
        }
        if (j >= 0) {
            sum += ctoi(num2[j]);
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
