#include <iostream>
#include <string>
#include <unordered_map>
#include <tuple>

using namespace std;

tuple<int, int, int> processDictionary(const unordered_map<string, string>& dictionary) {
    int count = 0;
    int sumKey = 0;
    int sumValue = 0;

    for (const auto& entry : dictionary) {
        count++;

        string key = entry.first;
        string value = entry.second;

        int keyNumber = stoi(key.substr(3));
        int valueNumber = stoi(value.substr(5));

        sumKey += keyNumber;
        sumValue += valueNumber;
    }

    return make_tuple(count, sumKey, sumValue);
}

int main() {
    unordered_map<string, string> dictionary = {
        {"key1", "value3"},
        {"key2", "value5"},
        {"key3", "value7"}
    };

    auto result = processDictionary(dictionary);

    cout << "Count: " << get<0>(result) << endl;
    cout << "Sum of key numbers: " << get<1>(result) << endl;
    cout << "Sum of value numbers: " << get<2>(result) << endl;

    return 0;
}
