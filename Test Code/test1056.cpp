#include <iostream>
#include <map>
#include <string>

enum class MojObject { TypeObject, TypeArray, TypeString, TypeNumber, TypeBool, TypeNull };

// Function to merge two JSON-like objects
void mergeInto(std::map<std::string, std::pair<MojObject, std::string>>& dest,
               const std::map<std::string, std::pair<MojObject, std::string>>& obj1,
               const std::map<std::string, std::pair<MojObject, std::string>>& obj2) {
    for (const auto& entry : obj1) {
        const auto& key = entry.first;
        const auto& value = entry.second;
        auto it = obj2.find(key);
        if (it != obj2.end()) {
            if (value.second == it->second.second) {
                dest[key] = value;
            } else if (value.first == MojObject::TypeObject && it->second.first == MojObject::TypeObject) {
                std::map<std::string, std::pair<MojObject, std::string>> merged;
                mergeInto(merged, value.second, it->second.second);
                dest[key] = std::make_pair(MojObject::TypeObject, merged);
            } else {
                dest[key] = it->second;
            }
        } else {
            dest[key] = value;
        }
    }
    for (const auto& entry : obj2) {
        if (dest.find(entry.first) == dest.end()) {
            dest[entry.first] = entry.second;
        }
    }
}

int main() {
    std::map<std::string, std::pair<MojObject, std::string>> dest = {
        {"key1", {MojObject::TypeString, "value1"}},
        {"key2", {MojObject::TypeObject, "value2"}},
        {"key3", {MojObject::TypeNumber, "123"}}
    };
    std::map<std::string, std::pair<MojObject, std::string>> obj1 = {
        {"key1", {MojObject::TypeString, "new_value1"}},
        {"key2", {MojObject::TypeObject, "new_value2"}},
        {"key4", {MojObject::TypeBool, "true"}}
    };
    std::map<std::string, std::pair<MojObject, std::string>> obj2 = {
        {"key1", {MojObject::TypeString, "new_value1"}},
        {"key2", {MojObject::TypeObject, "new_value2"}},
        {"key3", {MojObject::TypeNumber, "456"}}
    };

    mergeInto(dest, obj1, obj2);

    // Output the merged result
    for (const auto& entry : dest) {
        std::cout << entry.first << ": " << entry.second.second << std::endl;
    }

    return 0;
}
