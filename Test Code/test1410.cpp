#include <stdio.h>

int main() {
    int N, M, A = 0, x;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        A += x;
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &x);
        printf("%d\n", A - x);
    }
    return 0;
}
