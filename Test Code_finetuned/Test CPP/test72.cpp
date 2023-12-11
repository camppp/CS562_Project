#include <iostream>
using namespace std;

int main() {
    int matriz[3][2];

    // Read values into the matrix
    for(int i=0; i<3; i++) {
        for(int j=0; j<2; j++) {
            cin >> matriz[i][j];
        }
    }

    // Print the matrix
    for(int i=0; i<3; i++) {
        for(int j=0; j<2; j++) {
            cout << matriz[i][j] << " ";
        }
    }

    return 0;
}