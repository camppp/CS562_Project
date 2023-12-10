#include <iostream>
using namespace std;

int main() {
    int rows = 5;
    int count = 0;

    for (int i = 1; i <= rows; ++i) {
        for (int space = 1; space <= rows - i; ++space) {
            cout << " ";
        }

        while (count != 2 * i - 1) {
            if (count <= rows - 1) {
                cout << i + count << " ";
                ++count;
            } else {
                int temp = i + count - rows;
                cout << temp << " ";
                ++count;
            }
        }
        count = 0;
        cout << endl;
    }

    return 0;
}
