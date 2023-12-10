#include <unordered_map>
#include <string>

class StringInt64MapManager {
private:
    std::unordered_map<std::string, int64_t> stringToInt64Map;

public:
    StringInt64MapManager() {
        // Default constructor initializes the mapping data structure
    }

    void addMapping(const std::string& key, int64_t value) {
        stringToInt64Map[key] = value;
    }

    bool getValue(const std::string& key, int64_t& value) {
        auto it = stringToInt64Map.find(key);
        if (it != stringToInt64Map.end()) {
            value = it->second;
            return true;
        }
        return false;
    }

    bool removeMapping(const std::string& key) {
        auto it = stringToInt64Map.find(key);
        if (it != stringToInt64Map.end()) {
            stringToInt64Map.erase(it);
            return true;
        }
        return false;
    }

    void clearMappings() {
        stringToInt64Map.clear();
    }
};
