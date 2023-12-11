#include <iostream>
#include <string>
#include <unordered_map>

template <typename Key, typename Value>
class Map {
private:
    std::unordered_map<Key, Value> map;

public:
    Map() {}

    void insert(const Key& key, const Value& value) {
        map[key] = value;
    }

    Value& get(const Key& key) {
        return map[key];
    }

    void print() {
        for (const auto& entry : map) {
            std::cout << entry.first << " => " << entry.second << std::endl;
        }
    }
};

int main() {
    Map<std::string, int> map;

    map.insert("apple", 10);
    map.insert("banana", 20);
    map.insert("cherry", 30);

    std::cout << "Apple: " << map.get("apple") << std::endl;
    std::cout << "Banana: " << map.get("banana") << std::endl;
    std::cout << "Cherry: " << map.get("cherry") << std::endl;

    map.print();

    return 0;
}
