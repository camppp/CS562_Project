#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int calculateMainDiagonalSum(int** array, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array[i][i];
    }
    return sum;
}

int main() {
    ifstream fi("input.txt");
    int n, x, y;
    vector<pair<int, int>> dimen;

    while (fi >> x && fi >> y) {
        dimen.push_back(make_pair(x, y));
    }

    n = dimen.size();

    int** array = new int*[n];
    for (int i = 0; i < n; i++) array[i] = new int[n];

    for (int i = 0; i < n; i++) {
        array[i][0] = dimen[i].first;
        array[i][1] = dimen[i].second;
    }

    int diagonalSum = calculateMainDiagonalSum(array, n);
    cout << "Sum of elements on the main diagonal: " << diagonalSum << endl;

    for (int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
