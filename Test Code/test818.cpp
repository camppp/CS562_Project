template <typename KeyType, typename ValueType>
ValueType findInMap(const std::map<KeyType, ValueType>& fd_map_, const KeyType& key, const ValueType& default_value) {
    auto it = fd_map_.find(key);
    if (it != fd_map_.end()) {
        return it->second;
    } else {
        return default_value;
    }
}
