#include <iostream>
#include <string>
#include <optional>

class Dictionary {
public:
    std::optional<int> FindInt(const std::string& key) const {
        // Implementation of FindInt method
        // Assume it returns the optional integer value associated with the key
        // or an empty optional if the key is not present
    }
};

int processDictionary(const Dictionary& dict, const std::string& key) {
    int offset = dict.FindInt(key).value_or(0);
    return offset;
}

int main() {
    // Example usage
    Dictionary dict;
    // Populate the dictionary with key-value pairs
    // ...
    int result = processDictionary(dict, "offset");
    std::cout << "Result: " << result << std::endl;
    return 0;
}
