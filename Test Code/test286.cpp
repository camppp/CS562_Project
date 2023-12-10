std::string processArrays(const std::vector<int>& fa, const std::vector<int>& fb) {
    std::string result;
    for (int i = 0; i < fa.size(); i++) {
        if (fa[i] == 1 && fb[i] == 1) {
            result += "1 ";
        } else if (fa[i] == 0 && fb[i] == 0) {
            result += "0 ";
        } else {
            result += "nil ";
        }
    }
    return result;
}
