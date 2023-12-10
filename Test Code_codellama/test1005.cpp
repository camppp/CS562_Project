bool validateParentheses(string s) {
    stack<char> parentheses;
    for (char c : s) {
        if (c == '(') {
            parentheses.push(c);
        } else if (c == ')') {
            if (parentheses.empty()) {
                return false;
            }
            parentheses.pop();
        }
    }
    return parentheses.empty();
}
