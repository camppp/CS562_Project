#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class RightTriangle {
public:
    long long triangleCount(int places, int points, int a, int b, int c) {
        if (places & 1) {
            return 0;
        }
        set<long long> S;
        for (int i = 0; i < places; ++i) {
            S.insert(i);
        }

        vector<int> P;
        for (auto it : S) {
            P.push_back(it);
        }

        int count = 0;
        for (int i = 0; i < points; ++i) {
            for (int j = i + 1; j < points; ++j) {
                long long dist1 = abs(P[i] - P[j]);
                long long dist2 = abs(a - b);
                long long dist3 = abs(a - c);
                long long dist4 = abs(b - c);
                vector<long long> sides = {dist1, dist2, dist3, dist4};
                sort(sides.begin(), sides.end());
                if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2]) {
                    count++;
                }
            }
        }
        return count;
    }
};
