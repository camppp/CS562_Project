class DivisionCounter {
public:
    int countDivisions(int n) {
        // Round up odd numbers to the nearest even number
        if (n % 2 == 1) {
            n += 1;
        }

        int count = 0;
        while (n > 0) {
            n /= 2;
            count++;
        }

        return count;
    }
};
