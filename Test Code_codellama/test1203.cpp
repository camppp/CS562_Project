#include <iostream>
#include <vector>

using namespace std;

vector<int> simulateTapeOperations(vector<int> arr) {
    vector<int> tape;

    for (int i = 0; i < arr.size(); i++) {
        int op = arr[i];
        if (op > 0) {
            tape.push_back(op);
        } else if (op < 0) {
            if (!tape.empty()) {
                tape.pop_back();
            }
        }
    }

    return tape;
}

int main() {
    vector<int> arr = {5, -2, 7, -3, 1};
    vector<int> tape = simulateTapeOperations(arr);

    for (int i = 0; i < tape.size(); i++) {
        cout << tape[i] << " ";
    }
    cout << endl;

    return 0;
}
