#include <stdio.h>

int main() {
    int n, x;
    double y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        x = i + 1;
        y = (double)(x * x - 2 * x + 1);
        printf("%0.6lf\n", y);
    }
    return 0;
}
