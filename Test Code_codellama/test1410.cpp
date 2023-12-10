#include <iostream>

using namespace std;

int main() {
    int N, M, x;
    cin >> N;
    int A = 0;
    for (int i = 0; i < N; i++) {
        cin >> x;
        A += x;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> x;
        cout << A - x << endl;
    }
    return 0;
}
