#include <stdio.h>

void solve(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    printf("Sum of the first %d natural numbers is: %d\n", n, sum);
}

int main() {
    int n = 5;
    solve(n); // Output: Sum of the first 5 natural numbers is: 15
    return 0;
}
