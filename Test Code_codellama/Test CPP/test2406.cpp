#include <functional>
#include <unordered_map>

namespace nonstd {

template <class Key, class Value, class Hash = std::hash<Key>, class Equal = std::equal_to<Key>>
class CustomHashTable {
public:
    // Inserts a key-value pair into the hash table.
    void insert(const Key& key, const Value& value) {
        // Use the custom hash function to generate a hash code for the key.
        size_t hashCode = hashFunction(key);

        // Use the custom equality function to compare the key with the existing keys in the hash table.
        for (auto it = hashTable.begin(); it != hashTable.end(); ++it) {
            if (equalFunction(key, it->first)) {
                // If the key already exists in the hash table, update the value.
                it->second = value;
                return;
            }
        }

        // If the key does not exist in the hash table, insert a new key-value pair.
        hashTable.insert(std::make_pair(key, value));
    }

    // Retrieves the value associated with the given key.
    // Returns a pointer to the value if found, nullptr otherwise.
    Value* get(const Key& key) {
        // Use the custom hash function to generate a hash code for the key.
        size_t hashCode = hashFunction(key);

        // Use the custom equality function to compare the key with the existing keys in the hash table.
        for (auto it = hashTable.begin(); it != hashTable.end(); ++it) {
            if (equalFunction(key, it->first)) {
                // If the key exists in the hash table, return the associated value.
                return &it->second;
            }
        }

        // If the key does not exist in the hash table, return nullptr.
        return nullptr;
    }

    // Removes the key-value pair associated with the given key from the hash table.
    void remove(const Key& key) {
        // Use the custom hash function to generate a hash code for the key.
        size_t hashCode = hashFunction(key);

        // Use the custom equality function to compare the key with the existing keys in the hash table.
        for (auto it = hashTable.begin(); it != hashTable.end(); ++it) {
            if (equalFunction(key, it->first)) {
                // If the key exists in the hash table, remove it.
                hashTable.erase(it);
                return;
            }
        }
    }

    // Sets a custom hash function for the keys.
    void setHashFunction(const Hash& hashFunction) {
        this->hashFunction = hashFunction;
    }

    // Sets a custom equality function for the keys.
    void setEqualityFunction(const Equal& equalityFunction) {
        this->equalityFunction = equalityFunction;
    }

private:
    // The hash table used to store the key-value pairs.
    std::unordered_map<Key, Value, Hash, Equal> hashTable;

    // The custom hash function used to generate hash codes for the keys.
    Hash hashFunction;

    // The custom equality function used to compare keys.
    Equal equalityFunction;
};

} // namespace nonstd
