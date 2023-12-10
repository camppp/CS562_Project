#include <iostream>
#include <cmath>

using namespace std;

tuple<int, int> isPerfectPower(int n) {
    int a, b;
    for (a = 2; a <= n; a++) {
        b = (int)log(n) / log(a);
        if (pow(a, b) == n) {
            return make_tuple(a, b);
        }
    }
    return make_tuple(0, 0);
}

int main() {
    int n;
    cin >> n;
    tuple<int, int> result = isPerfectPower(n);
    if (result.first != 0) {
        cout << "The number " << n << " is a perfect power of " << result.first << " raised to the power of " << result.second << "." << endl;
    } else {
        cout << "The number " << n << " is not a perfect power." << endl;
    }
    return 0;
}
