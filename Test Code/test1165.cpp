#include <iostream>
#include <algorithm>
using namespace std;

const int Mmax = 1005;

long long maxSumSubarray(int arr[], int n) {
    long long maxEndingHere = 0, maxSoFar = 0;
    for (int i = 0; i < n; i++) {
        maxEndingHere = max((long long)arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

long long maxSumSubarray2D(int n, int m, int a[n][m]) {
    long long UpSum[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        UpSum[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) {
        UpSum[0][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            UpSum[i][j] = UpSum[i - 1][j] + a[i - 1][j - 1];
        }
    }

    long long ans = a[0][0];
    for (int r1 = 0; r1 < n; r1++) {
        for (int r2 = r1; r2 < n; r2++) {
            long long v[Mmax];
            for (int i = 0; i < m; i++) {
                v[i] = UpSum[r2 + 1][i + 1] - UpSum[r1][i + 1];
            }
            ans = max(ans, maxSumSubarray(v, m));
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cout << maxSumSubarray2D(n, m, a) << endl;
    return 0;
}
