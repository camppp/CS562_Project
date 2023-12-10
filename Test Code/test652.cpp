#include <cmath>

class DivisionCounter {
public:
    int countDivisions(int n) {
        if (n % 2 != 0) {
            n = ceil(n / 2.0) * 2;  // Round up odd numbers to the nearest even number
        }
        int res = 0;
        while (n > 0) {
            n /= 2;
            res++;
        }
        return res;
    }
};
