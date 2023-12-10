class Solution {
public:
    set<int> ss;

    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) {
            return -1; // If K is divisible by 2 or 5, it will never be possible to find a positive integer N consisting only of the digit 1 that is a multiple of K.
        }

        int remainder = 0;
        for (int length = 1; length <= K; length++) {
            remainder = (remainder * 10 + 1) % K;
            if (remainder == 0) {
                return length; // If the remainder becomes 0, it means we have found a positive integer N consisting only of the digit 1 that is a multiple of K.
            }
        }

        return -1; // If no such N is found within the first K iterations, return -1.
    }
};
