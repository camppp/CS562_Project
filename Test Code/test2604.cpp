++
#include <iostream>
using namespace std;

typedef long long ll;

ll merge(int *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    ll inversions = 0;
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            inversions += n1 - i;  // Count inversions
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    return inversions;
}

ll mergeSort(int *arr, int l, int r) {
    if (r > l) {
        int m = l + (r - l) / 2;
        ll inversions = 0;
        inversions += mergeSort(arr, l, m);
        inversions += mergeSort(arr, m + 1, r);
        inversions += merge(arr, l, m, r);
        return inversions;
    }
    return 0;
}

ll countInversions(int *arr, int n) {
    return mergeSort(arr, 0, n - 1);
}

int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Number of inversions: " << countInversions(arr, n) << endl;
    return 0;
}
