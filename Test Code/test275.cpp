#include "hash.hh"
#include <vector>
#include <list>

class HashTable {
private:
    int size;
    std::vector<std::list<std::pair<int, std::string>>> table;

public:
    HashTable(int size) : size(size), table(size) {}

    void insert(int key, const std::string& value) {
        int index = hashFunction(key, size);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                // Key already exists, update the value
                pair.second = value;
                return;
            }
        }
        table[index].push_back(std::make_pair(key, value));
    }

    void remove(int key) {
        int index = hashFunction(key, size);
        table[index].remove_if([key](const std::pair<int, std::string>& pair) {
            return pair.first == key;
        });
    }

    std::string retrieve(int key) {
        int index = hashFunction(key, size);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return "";  // Key not found
    }

    bool exists(int key) {
        int index = hashFunction(key, size);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return true;
            }
        }
        return false;
    }
};
