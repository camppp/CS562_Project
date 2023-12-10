#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> findMissingNumbers(const vector<string>& dict) {
    vector<int> missingNumbers;
    int expected = 1;
    for (const string& numStr : dict) {
        int num = stoi(numStr);
        while (num > expected) {
            missingNumbers.push_back(expected);
            expected++;
        }
        if (num == expected) {
            expected++;
        }
    }
    while (expected <= 1000) {
        missingNumbers.push_back(expected);
        expected++;
    }
    return missingNumbers;
}

int main() {
    vector<string> dict = {"1", "2", "4", "5", "7", "10"};
    vector<int> missing = findMissingNumbers(dict);
    for (int num : missing) {
        cout << num << " ";
    }
    return 0;
}
