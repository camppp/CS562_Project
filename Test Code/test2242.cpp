#include <iostream>
#include <cmath>

bool sameLine(int c1, int c2, int c3, int c4) {
    return (c1 == c3) || (c2 == c4);
}

bool sameDiagonal(int c1, int c2, int c3, int c4) {
    return (abs(c1 - c3) == abs(c2 - c4));
}

int main() {
    int c1, c2, c3, c4;
    std::cin >> c1 >> c2 >> c3 >> c4;

    if (c1 == c3 && c2 == c4) {
        std::cout << 0; // No moves required
    } else if (sameLine(c1, c2, c3, c4) || sameDiagonal(c1, c2, c3, c4)) {
        std::cout << 1; // One move required to transform the point
    } else {
        std::cout << 2; // Two moves required to transform the point
    }

    return 0;
}
