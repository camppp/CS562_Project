#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", n/2); // Print the largest sum of distinct positive integers that add up to n

    // Print the distinct positive integers that add up to n
    for(int i=1; i<n/2; i++){
        printf("2 ");
    }
    printf(n%2==0 ? "2" : "3");
    return 0;
}
