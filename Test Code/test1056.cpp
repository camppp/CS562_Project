#include <iostream>
#include <string>
#include <map>

using namespace std;

void mergeInto(map<string, string>& dest, const map<string, string>& obj1, const map<string, string>& obj2) {
    for (const auto& kvp1 : obj1) {
        const string& key = kvp1.first;
        const string& value1 = kvp1.second;
        const string& value2 = obj2.find(key)->second;

        if (value1 == value2) {
            dest[key] = value1;
        } else if (value1.is_object() && value2.is_object()) {
            mergeInto(dest[key], value1, value2);
        } else {
            dest[key] = value2;
        }
    }
}

int main() {
    map<string, string> obj1 = {
        {"key1", "value1"},
        {"key2", "value2"},
        {"key3", "value3"}
    };

    map<string, string> obj2 = {
        {"key1", "new_value1"},
        {"key2", "new_value2"},
        {"key4", "value4"}
    };

    map<string, string> dest;
    mergeInto(dest, obj1, obj2);

    for (const auto& kvp : dest) {
        cout << kvp.first << ": " << kvp.second << endl;
    }

    return 0;
}
