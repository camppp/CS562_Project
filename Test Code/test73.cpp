#include <iostream>
using namespace std;

int main() {
    int matriz[3][2];

    // Read values into the matrix
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 2; c++) {
            cin >> matriz[l][c];
        }
    }

    // Print the matrix
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 2; c++) {
            cout << matriz[l][c] << " ";
        }
        cout << endl;
    }

    return 0;
}
