#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

pair<vector<ll>, vector<ll>> calculateProducts(vector<ll> c) {
    int n = c.size();
    vector<ll> ab(n);
    vector<ll> bc(n);

    ab[0] = 1;
    bc[n-1] = 1;

    for (int i = 1; i < n; ++i) {
        ab[i] = ab[i-1] * c[i-1];
        bc[n-i-1] = bc[n-i] * c[n-i];
    }

    return make_pair(ab, bc);
}

int main() {
    int n;
    cin >> n;
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    pair<vector<ll>, vector<ll>> result = calculateProducts(c);
    vector<ll> ab = result.first;
    vector<ll> bc = result.second;

    cout << "ab = {";
    for (int i = 0; i < n; ++i) {
        cout << ab[i];
        if (i < n-1) cout << ", ";
    }
    cout << "}" << endl;

    cout << "bc = {";
    for (int i = 0; i < n; ++i) {
        cout << bc[i];
        if (i < n-1) cout << ", ";
    }
    cout << "}" << endl;

    return 0;
}
