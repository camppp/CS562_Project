#include <iostream>
#include <string>
#include <tuple>
#include <type_traits>

// Helper function to convert any type to string
template <typename T>
std::string to_string(const T& value) {
    return std::to_string(value);
}

// Key-value pair structure
template <typename Key, typename Value>
struct Entry {
    Key key;
    Value value;

    void print() const {
        std::cout << key << ": " << to_string(value) << std::endl;
    }
};

// Variadic template class Map
template <typename... Entries>
class Map {
public:
    // Print all key-value pairs in the map
    void print() const {
        (Entries.print(), ...);
    }

    // Insert a key-value pair into the map
    template <typename Key, typename Value>
    void insert(const Key& key, const Value& value) {
        using NewEntry = Entry<Key, Value>;
        entries_ = std::tuple_cat(entries_, std::make_tuple(NewEntry{key, value}));
    }

    // Retrieve the value associated with a given key
    template <typename Key>
    auto get(const Key& key) const {
        return get_impl(key, std::index_sequence_for<Entries...>{});
    }

private:
    // Helper function to retrieve the value associated with a given key
    template <typename Key, std::size_t... Is>
    auto get_impl(const Key& key, std::index_sequence<Is...>) const {
        return std::make_tuple(get_entry<Entries>(key, Is)...);
    }

    // Helper function to retrieve the value associated with a given key for a specific entry
    template <typename Entry, typename Key>
    auto get_entry(const Key& key) const {
        if constexpr (std::is_same_v<typename Entry::key_type, Key>) {
            return Entry.value;
        } else {
            // Return a default value if the key is not found
            return typename Entry::value_type{};
        }
    }

    std::tuple<Entries...> entries_;
};

int main() {
    Map<Entry<int, std::string>, Entry<std::string, double>> myMap;
    myMap.insert(1, "one");
    myMap.insert("pi", 3.14159);
    myMap.print();

    auto value1 = myMap.get(1);  // Retrieves "one"
    auto value2 = myMap.get("pi");  // Retrieves 3.14159
    return 0;
}
