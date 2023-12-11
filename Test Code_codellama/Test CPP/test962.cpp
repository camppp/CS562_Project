class Solution {
public:
    set<int> ss;

    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0) {
            return -1;
        }

        int N = 1;
        while (N % K != 0) {
            N *= 10;
            N += 1;
        }

        return N.length();
    }
};
