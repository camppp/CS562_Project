#include <iostream>
#include <vector>

using namespace std;

pair<vector<long long>, vector<long long>> calculateProducts(vector<long long> c) {
    int n = c.size();
    vector<long long> ab(n), bc(n);
    for (int i = 0; i < n; i++) {
        ab[i] = 1;
        bc[n-i-1] = 1;
        for (int j = 0; j < i; j++) {
            ab[i] *= c[j];
        }
        for (int j = n-i-1; j < n; j++) {
            bc[n-i-1] *= c[j];
        }
    }
    return make_pair(ab, bc);
}

int main() {
    int n;
    cin >> n;
    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    pair<vector<long long>, vector<long long>> result = calculateProducts(c);
    for (int i = 0; i < n; i++) {
        cout << result.first[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << result.second[i] << " ";
    }
    cout << endl;
    return 0;
}
