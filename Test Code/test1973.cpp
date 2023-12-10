#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int i, int j) {
    return a[i] < a[j];
}

void findPairsWithMinSumIndices(int a[], int n) {
    int x[n];
    int tot = 0;
    for(int i=0; i<n; i++) {
        tot += a[i];
        x[i] = i;
    }
    sort(x, x+n, cmp);
    int l = n / 2;
    for(int i=0; i<l; i++) {
        cout << x[i]+1 << " " << x[n-i-1]+1 << endl;
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    findPairsWithMinSumIndices(a, n);
    return 0;
}
