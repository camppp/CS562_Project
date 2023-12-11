#include <iostream>

int main() {
    int test_cases;
    cin >> test_cases;

    bool found = false;

    for (int i = 0; i < test_cases; i++) {
        int n;
        cin >> n;

        if (n > 30) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
