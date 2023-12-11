#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n, k;
    cin >> n;
    vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }
    cin >> k;
    sort(seq.begin(), seq.end());
    cout << seq[k - 1] << endl;
    return 0;
}
