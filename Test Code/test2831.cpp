#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

struct KeyValue {
    string key;
    string value;
};

vector<KeyValue> parseKeyValue(const string& input) {
    vector<KeyValue> keyValues;
    stringstream ss(input);
    string key, value;

    while (ss >> key >> value) {
        if (key.empty() || value.empty()) {
            throw runtime_error("Bad KV spec empty key");
        }
        keyValues.push_back({key, value});
    }

    return keyValues;
}

int main() {
    string input = "name=John,age=30,city=New York";
    vector<KeyValue> keyValues = parseKeyValue(input);

    for (const auto& kv : keyValues) {
        cout << kv.key << ": " << kv.value << endl;
    }

    return 0;
}
