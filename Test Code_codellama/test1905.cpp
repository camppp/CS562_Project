#include <iostream>
#include <vector>

using namespace std;

vector<int> primeFactors(int n) {
    vector<int> factors;
    while (n > 1) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                n /= i;
                break;
            }
        }
    }
    return factors;
}

int main() {
    int n;
    cin >> n;
    vector<int> factors = primeFactors(n);
    for (int i = 0; i < factors.size(); i++) {
        cout << factors[i] << " ";
    }
    cout << endl;
    return 0;
}
