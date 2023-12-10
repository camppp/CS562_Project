int processDictionary(const Dictionary& dict, const std::string& key) {
    auto result = dict.FindInt(key);
    if (result) {
        return *result;
    } else {
        return 0;
    }
}
