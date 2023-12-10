bool isBalancedBraces(const string& code) {
    stack<char> braces;
    for (int i = 0; i < code.size(); i++) {
        if (code[i] == '{') {
            braces.push('{');
        } else if (code[i] == '}') {
            if (braces.empty()) {
                return false;
            }
            braces.pop();
        }
    }
    return braces.empty();
}
