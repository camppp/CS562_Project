template <typename T>
std::vector<T> dropWhile(const std::vector<T>& seq, const std::function<bool(T)>& pred) {
    std::vector<T> result;
    for (const auto& elem : seq) {
        if (!pred(elem)) {
            result.push_back(elem);
        }
    }
    return result;
}
