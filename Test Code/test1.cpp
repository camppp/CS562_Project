class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) {
            return false;
        }
        
        int sum = 1; // Start with 1 as a divisor
        
        // Check for divisors up to the square root of the number
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                if (i != num / i) {
                    sum += num / i;
                }
            }
        }
        
        // If the sum of divisors is equal to the number, it's a perfect number
        return sum == num;
    }
};
