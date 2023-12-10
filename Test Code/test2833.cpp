#include <stdio.h>

int maxQualityOfWine(int n, int barrels[]) {
    int maxQuality = 0;
    for (int i = 0; i < n; i++) {
        int work = 0, prework = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (barrels[i] > barrels[j]) {
                    work = prework + barrels[j];
                    if (work > barrels[i]) {
                        work = barrels[i];
                    }
                } else {
                    work = prework + barrels[i];
                }
                if (work > maxQuality) {
                    maxQuality = work;
                }
                prework = work;
            }
        }
    }
    return maxQuality;
}

int main() {
    int n;
    printf("Enter the number of barrels: ");
    scanf("%d", &n);
    if (n > 0) {
        int barrels[n];
        printf("Enter the initial quality of wine in each barrel: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &barrels[i]);
        }
        int maxQuality = maxQualityOfWine(n, barrels);
        printf("Maximum quality of wine that can be achieved: %d\n", maxQuality);
    } else {
        printf("Invalid number of barrels.\n");
    }
    return 0;
}
