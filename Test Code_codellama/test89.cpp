#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> processIdentifiers(const vector<string>& identifiers, const vector<string>& labels) {
    map<string, string> processedIdentifiers;

    for (int i = 0; i < identifiers.size(); i++) {
        string identifier = identifiers[i];
        string label = labels[i];

        if (identifier.empty()) {
            identifier = "POS_ID";
        }

        if (label.empty()) {
            label = "MISSING_LABEL";
        }

        processedIdentifiers[identifier] = label;
    }

    return processedIdentifiers;
}

int main() {
    vector<string> identifiers = {"id1", "", "id3"};
    vector<string> labels = {"label1", "label2"};

    map<string, string> processedIdentifiers = processIdentifiers(identifiers, labels);

    for (const auto& pair : processedIdentifiers) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
