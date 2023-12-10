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

    // Read pairs of integers into the vector dimen using the given code snippet
    while (fi >> n >> x >> y) {
        dimen.push_back(make_pair(n, x));
        dimen.push_back(make_pair(n, y));
    }

    // Initialize a 2D array array of size n x n using dynamic memory allocation
    int** array = new int*[n];
    for (int i = 0; i < n; i++) array[i] = new int[n];

    // Populate the 2D array array with the values from the vector dimen
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = dimen[i].first * dimen[j].second;
        }
    }

    // Call the function calculateMainDiagonalSum and output the result
    int sum = calculateMainDiagonalSum(array, n);
    cout << "Sum of elements on the main diagonal: " << sum << endl;

    // Deallocate memory for the 2D array
    for (int i = 0; i < n; i++) delete[] array[i];
    delete[] array;

    return 0;
}
