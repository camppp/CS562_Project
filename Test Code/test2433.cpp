#include "class.hpp"

void KeyValueStore::set(const std::string& key, const std::string& value) {
    data[key] = value;
    saveToFile();
}

std::optional<std::string> KeyValueStore::get(const std::string& key) {
    loadFromFile();
    auto it = data.find(key);
    if (it != data.end()) {
        return it->second;
    } else {
        return std::nullopt;
    }
}

void KeyValueStore::remove(const std::string& key) {
    data.erase(key);
    saveToFile();
}

void KeyValueStore::loadFromFile() {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            auto pos = line.find('=');
            if (pos != std::string::npos) {
                data[line.substr(0, pos)] = line.substr(pos + 1);
            }
        }
        file.close();
    }
}

void KeyValueStore::saveToFile() {
    std::ofstream file(filename, std::ios::trunc);
    if (file.is_open()) {
        for (const auto& pair : data) {
            file << pair.first << "=" << pair.second << std::endl;
        }
        file.close();
    }
}
