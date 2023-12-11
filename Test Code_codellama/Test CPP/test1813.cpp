#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    double average = 0;
    for (int i = 0; i < n; i++) {
        average += arr[i];
    }
    average /= n;

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > average) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
