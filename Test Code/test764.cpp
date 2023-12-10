#include <stdio.h>

int main() {
    int n, x;
    double y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);  // Input the value of x
        y = (double)(x * x - 2 * x + 1);  // Calculate the value of f(x)
        printf("%0.6lf\n", y);  // Print the result with 6 decimal places
    }
    return 0;
}
