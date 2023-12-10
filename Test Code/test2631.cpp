std::vector<std::vector<int>> combine(std::vector<std::vector<int>> vv, unsigned int level, unsigned int nfs) {
    std::vector<std::vector<int>> result;
    for (const auto& v : vv) {
        for (unsigned int i = 0; i < v.size(); i++) {
            if (i == level) {
                std::vector<int> new_combination;
                for (const auto& c : v) {
                    new_combination.push_back(c);
                }
                new_combination.push_back(i);
                if (new_combination.size() <= nfs) {
                    result.push_back(new_combination);
                }
            }
        }
    }
    return result;
}
