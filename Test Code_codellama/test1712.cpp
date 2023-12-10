#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> mergeData(map<string, string> data1, map<string, string> data2, string identifier) {
    map<string, string> mergedData;

    for (auto it = data1.begin(); it != data1.end(); ++it) {
        if (it->first == identifier) {
            mergedData[it->first] = it->second;
        }
    }

    for (auto it = data2.begin(); it != data2.end(); ++it) {
        if (it->first == identifier) {
            mergedData[it->first] = it->second;
        }
    }

    return mergedData;
}

int main() {
    map<string, string> data1 = {
        {"NEMOQMLPLUGINS_SOCIAL_CONTENTITEMID", "123"},
        {"key1", "value1"},
        {"key2", "value2"}
    };

    map<string, string> data2 = {
        {"FACEBOOK_ONTOLOGY_METADATA_ID", "123"},
        {"key3", "value3"},
        {"key4", "value4"}
    };

    string identifier = "NEMOQMLPLUGINS_SOCIAL_CONTENTITEMID";

    map<string, string> mergedData = mergeData(data1, data2, identifier);

    for (auto it = mergedData.begin(); it != mergedData.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}
