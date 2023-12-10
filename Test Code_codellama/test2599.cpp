#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, vector<string>> synonyms;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "ADD") {
            string w1, w2;
            cin >> w1 >> w2;
            synonyms[w1].push_back(w2);
            synonyms[w2].push_back(w1);
        } else if (command == "CHECK") {
            string w1, w2;
            cin >> w1 >> w2;
            if (synonyms.find(w1) != synonyms.end() &&
                find(synonyms[w1].begin(), synonyms[w1].end(), w2) != synonyms[w1].end()) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if (command == "COUNT") {
            string w;
            cin >> w;
            cout << synonyms[w].size() << endl;
        }
    }

    return 0;
}
