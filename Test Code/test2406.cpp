#include <functional>
#include <vector>
#include <list>

template <class Key, class Value, class Hash = std::hash<Key>, class Equal = std::equal_to<Key>>
class CustomHashTable {
private:
    using KeyValuePair = std::pair<Key, Value>;
    using Bucket = std::list<KeyValuePair>;
    std::vector<Bucket> table;
    Hash hashFunction;
    Equal equalityFunction;

    size_t getBucketIndex(const Key& key) const {
        return hashFunction(key) % table.size();
    }

public:
    CustomHashTable(size_t initialSize = 10) : table(initialSize) {}

    void insert(const Key& key, const Value& value) {
        size_t index = getBucketIndex(key);
        for (auto& pair : table[index]) {
            if (equalityFunction(pair.first, key)) {
                pair.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    Value* get(const Key& key) {
        size_t index = getBucketIndex(key);
        for (auto& pair : table[index]) {
            if (equalityFunction(pair.first, key)) {
                return &pair.second;
            }
        }
        return nullptr;
    }

    void remove(const Key& key) {
        size_t index = getBucketIndex(key);
        table[index].remove_if([&](const KeyValuePair& pair) {
            return equalityFunction(pair.first, key);
        });
    }

    void setHashFunction(const Hash& hashFunction) {
        this->hashFunction = hashFunction;
    }

    void setEqualityFunction(const Equal& equalityFunction) {
        this->equalityFunction = equalityFunction;
    }
};
