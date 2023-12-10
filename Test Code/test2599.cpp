#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, set<string>> synonyms;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "ADD") {
            string w1, w2;
            cin >> w1 >> w2;
            if (synonyms.find(w1) != synonyms.end()) {
                synonyms[w1].insert(w2);
            } else {
                set<string> s;
                s.insert(w2);
                synonyms[w1] = s;
            }
        } else if (command == "CHECK") {
            string w1, w2;
            cin >> w1 >> w2;
            if (synonyms.find(w1) != synonyms.end() && synonyms[w1].count(w2) > 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if (command == "COUNT") {
            string w;
            cin >> w;
            if (synonyms.find(w) != synonyms.end()) {
                cout << synonyms[w].size() << endl;
            } else {
                cout << "0" << endl;
            }
        }
    }
    return 0;
}
