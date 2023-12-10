#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string jane_down, john_down;
    while (cin >> jane_down >> john_down) {
        // Perform simulation
        if (jane_down.size() == john_down.size()) {
            if (jane_down < john_down) {
                cout << "Jane wins this round." << endl;
            } else {
                cout << "John wins this round." << endl;
            }
        } else if (jane_down.size() > john_down.size()) {
            cout << "Jane wins this round." << endl;
        } else {
            cout << "John wins this round." << endl;
        }
    }
    return 0;
}
