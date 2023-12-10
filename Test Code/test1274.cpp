ccstd::string &StringUtil::toupper(ccstd::string &str) {
    for (char &c : str) {
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';  // Convert lowercase letter to uppercase
        }
    }
    return str;
}
