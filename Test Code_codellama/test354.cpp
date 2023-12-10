#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> sequence;
    int query;

    // Read the sequence of integers
    while (cin >> query) {
        sequence.push_back(query);
    }

    // Read the queries
    while (cin >> query) {
        // Find the first occurrence of the queried integer in the sequence
        auto it = find(sequence.begin(), sequence.end(), query);
        if (it != sequence.end()) {
            // Output the index of the first occurrence
            cout << it - sequence.begin() << endl;
        } else {
            // Output -1 if the integer is not found
            cout << -1 << endl;
        }
    }

    return 0;
}
