#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    int in[n];
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    int sum = accumulate(in, in+n, 0);
    int average = sum / n;

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (in[i] > average) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
