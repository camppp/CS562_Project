#include <iostream>
#include <vector>

struct I2Point {
    int x, y;
};

namespace nvector {
    template <typename T>
    std::vector<T> Read(int n) {
        std::vector<T> vec(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> vec[i].x >> vec[i].y;
        }
        return vec;
    }
}

bool CheckCollinear(const I2Point& p1, const I2Point& p2, const I2Point& p3) {
    return (p2.y - p1.y) * (p3.x - p2.x) == (p3.y - p2.y) * (p2.x - p1.x);
}

int main() {
    char c;
    std::cin >> c;
    auto vp = nvector::Read<I2Point>(3);
    bool b = false;
    for (unsigned i = 0; i < 3; ++i) {
        if (i < 2) {
            b = CheckCollinear(vp[i], vp[i + 1], vp[i + 2]);
            if (!b) {
                break;
            }
        }
    }
    std::cout << "Points are collinear: " << std::boolalpha << b << std::endl;
    return 0;
}
