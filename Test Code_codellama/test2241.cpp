#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxElementsSumLessThanX(int N, int M, int X, int A[], int B[]) {
    vector<int> a(A, A + N);
    vector<int> b(B, B + M);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    int sum = 0;
    int count = 0;
    while (i < N && j < M) {
        if (sum + a[i] + b[j] <= X) {
            sum += a[i] + b[j];
            count++;
            i++;
            j++;
        } else if (sum + a[i] <= X) {
            sum += a[i];
            count++;
            i++;
        } else {
            sum += b[j];
            count++;
            j++;
        }
    }
    return count;
}

int main() {
    int N, M, X;
    cin >> N >> M >> X;
    int A[N], B[M];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    int result = maxElementsSumLessThanX(N, M, X, A, B);
    cout << result << endl;
    return 0;
}
