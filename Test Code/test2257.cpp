#include <iostream>
#include <vector>
using namespace std;

int minPatches(int N, int L, vector<int>& holes) {
    int patches = 0;
    long long ini = 0, actual;
    int i = 0;
    while (ini < N) {
        if (i < N && holes[i] <= ini + L) {
            actual = holes[i];
            i++;
        } else {
            actual = ini + L;
            patches++;
        }
        ini = actual;
    }
    return patches;
}

int main() {
    int N = 5;
    int L = 3;
    vector<int> holes = {1, 3, 7, 10, 12};
    cout << minPatches(N, L, holes); // Output: 3
    return 0;
}
