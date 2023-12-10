#include "class.hpp"

void KeyValueStore::loadFromFile() {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            size_t pos = line.find('=');
            if (pos != std::string::npos) {
                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos + 1);
                data[key] = value;
            }
        }
        file.close();
    }
}

void KeyValueStore::saveToFile() {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& pair : data) {
            file << pair.first << "=" << pair.second << "\n";
        }
        file.close();
    }
}

void KeyValueStore::set(const std::string& key, const std::string& value) {
    loadFromFile();
    data[key] = value;
    saveToFile();
}

std::optional<std::string> KeyValueStore::get(const std::string& key) {
    loadFromFile();
    if (data.find(key) != data.end()) {
        return data[key];
    }
    return std::nullopt;
}

void KeyValueStore::remove(const std::string& key) {
    loadFromFile();
    data.erase(key);
    saveToFile();
}
