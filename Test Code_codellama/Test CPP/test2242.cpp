#include <iostream>
#include <cmath>

using namespace std;

bool sameLine(int c1, int c2, int c3, int c4) {
    return (c1 * c3 + c2 * c4) == 0;
}

bool sameDiagonal(int c1, int c2, int c3, int c4) {
    return (c1 * c3 + c2 * c4) == (c1 - c3) * (c1 - c3) + (c2 - c4) * (c2 - c4);
}

int minMoves(int c1, int c2, int c3, int c4) {
    if (sameLine(c1, c2, c3, c4)) {
        return abs(c1 - c3) + abs(c2 - c4);
    } else if (sameDiagonal(c1, c2, c3, c4)) {
        return abs(c1 - c3) + abs(c2 - c4);
    } else {
        return -1;
    }
}

int main() {
    int c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    cout << minMoves(c1, c2, c3, c4) << endl;
    return 0;
}
