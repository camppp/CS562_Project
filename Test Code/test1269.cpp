#include <iostream>
using namespace std;

int main() {
    int cases, n;
    bool found;

    cin >> cases;
    while (cases--) {
        found = false;
        cin >> n;
        if (n > 30) {
            found = true;
        }
        cout << (found ? "true" : "false") << endl;
    }

    return 0;
}
