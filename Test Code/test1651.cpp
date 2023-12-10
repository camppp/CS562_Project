#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDie() {
    return rand() % 6 + 1;
}

int rollDiceGame() {
    int totalScore = 0;
    int roll;
    srand(time(NULL));

    do {
        roll = rollDie();
        printf("Roll: %d, Total score: %d\n", roll, totalScore + roll);
        if (roll == 1) {
            totalScore = 0;
            printf("Final score: %d\n", totalScore);
            return totalScore;
        }
        totalScore += roll;
        printf("Total score: %d\n", totalScore);
        printf("Enter 1 to stop, 0 to roll again: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Final score: %d\n", totalScore);
            return totalScore;
        }
    } while (1);
}

int main() {
    rollDiceGame();
    return 0;
}
