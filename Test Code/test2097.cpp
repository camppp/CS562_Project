#include <iostream>
using namespace std;

int* bubbleSort(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swap a[j] and a[j+1]
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return a;
}

int main() {
    int size = 5;
    int a[] = {64, 34, 25, 12, 22};
    
    cout << "The unsorted array is: ";
    for (int i = 0; i < size; i++) {
        cout << " " << a[i] << " ";
    }
    
    int* sortedArray = bubbleSort(a, size);
    
    cout << "\nThe sorted array is: ";
    for (int i = 0; i < size; i++) {
        cout << " " << sortedArray[i] << " ";
    }
    
    return 0;
}
