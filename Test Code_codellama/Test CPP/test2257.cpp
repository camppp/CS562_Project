#include <iostream>
#include <vector>

using namespace std;

int minPatches(int N, int L, vector<int> &holes) {
    int numPatches = 0;
    int currentPosition = 0;

    for (int i = 0; i < N; i++) {
        int holePosition = holes[i];

        // Check if the hole can be covered by an existing patch
        if (holePosition - currentPosition < L) {
            currentPosition = holePosition;
            continue;
        }

        // If the hole cannot be covered, add a new patch
        numPatches++;
        currentPosition = holePosition - L + 1;
    }

    return numPatches;
}

int main() {
    int N = 5;
    int L = 3;
    vector<int> holes = {1, 3, 7, 10, 12};

    cout << minPatches(N, L, holes) << endl;

    return 0;
}
