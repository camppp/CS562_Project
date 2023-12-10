#include <iostream>
using namespace std;

int findMax(int arr[], int size) {
    if (size == 0) {
        cerr << "Error: Empty array" << endl;
        return INT_MIN;  // Return the minimum possible integer value
    }

    int maxElement = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    return maxElement;
}
