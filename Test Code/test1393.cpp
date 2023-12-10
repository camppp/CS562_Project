#include <bits/stdc++.h>

using namespace std;
inline long long int MIN(long long int a, long long int b) { return (a > b) ? b : a; }

int main() {
    int t;
    cin >> t;  // Input for the number of test cases

    while (t--) {
        long long int n, m;
        cin >> n >> m;  // Input for the pair of integers

        cout << MIN(n, m) << endl;  // Output the minimum of the two integers
    }

    return 0;
}
