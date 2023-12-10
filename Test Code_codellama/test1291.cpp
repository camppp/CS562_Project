#include <iostream>
#include <map>

string findMaxKey(map<string, int> m) {
    string maxKey = "";
    int maxValue = 0;

    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second > maxValue) {
            maxValue = it->second;
            maxKey = it->first;
        }
    }

    return maxKey;
}

int main() {
    map<string, int> m = {{"apple", 3}, {"banana", 2}, {"cherry", 3}, {"date", 1}};
    string maxKey = findMaxKey(m);
    cout << "The key with the highest value is: " << maxKey << endl;
    return 0;
}
