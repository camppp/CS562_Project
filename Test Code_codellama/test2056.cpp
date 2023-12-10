void arLanguage::insert(const std::string& name, arDataTemplate* data) {
    std::lock_guard<std::mutex> guard(_mutex);
    _dictionary[name] = data;
}

void arLanguage::remove(const std::string& name) {
    std::lock_guard<std::mutex> guard(_mutex);
    _dictionary.erase(name);
}

bool arLanguage::exists(const std::string& name) {
    std::lock_guard<std::mutex> guard(_mutex);
    return _dictionary.find(name) != _dictionary.end();
}
