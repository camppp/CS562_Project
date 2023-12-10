#include <iostream>
#include <string>
#include <vector>

// Functor to output key-value pairs to the console in a specific format
struct OutputKeyValuePairs {
    void operator()(const std::string& key, const std::vector<int>& value) {
        std::cout << key << ": ";
        for (const int& v : value) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Create a mapping with string keys and vector values
    Mapping<std::string, std::vector<int>> mapping;

    // Add some key-value pairs to the mapping
    mapping.AddMapping("key1", {1, 2, 3});
    mapping.AddMapping("key2", {4, 5, 6});
    mapping.AddMapping("key3", {7, 8, 9});

    // Apply the functor to each key-value pair in the mapping
    mapping.ForEachMapping(OutputKeyValuePairs());

    return 0;
}
