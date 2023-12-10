#include <stdio.h>

float performOperation(int ab, int Pg, int nK, int dO, int S, int tK8d, int r5c) {
    if (S + tK8d == 0) {
        printf("Error: Division by zero\n");
        return 0;
    }
    return (ab * Pg) + ((float)(nK - dO) / (S + tK8d)) - r5c;
}

int main() {
    int ab = 5, Pg = 3, nK = 10, dO = 2, S = 4, tK8d = 0, r5c = 7;
    float result = performOperation(ab, Pg, nK, dO, S, tK8d, r5c);
    printf("Result: %.2f\n", result);
    return 0;
}
