void RemoveIgnore(std::string &ignores) {
    int att = _dataframe.GetAttributeIndex(ignores);
    auto result = std::find(_ignores.begin(), _ignores.end(), att);
    if (result != _ignores.end()) {
        _ignores.erase(result);
    }
}
