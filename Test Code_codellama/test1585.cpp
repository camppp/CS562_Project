#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* playRockPaperScissors(char* userChoice) {
    char computerChoice[10];
    srand(time(NULL));
    int randomNumber = rand() % 3;
    switch (randomNumber) {
        case 0:
            strcpy(computerChoice, "rock");
            break;
        case 1:
            strcpy(computerChoice, "paper");
            break;
        case 2:
            strcpy(computerChoice, "scissors");
            break;
    }
    if (strcmp(userChoice, computerChoice) == 0) {
        return "It's a tie!";
    } else if (strcmp(userChoice, "rock") == 0 && strcmp(computerChoice, "paper") == 0) {
        return "You lose!";
    } else if (strcmp(userChoice, "rock") == 0 && strcmp(computerChoice, "scissors") == 0) {
        return "You win!";
    } else if (strcmp(userChoice, "paper") == 0 && strcmp(computerChoice, "rock") == 0) {
        return "You win!";
    } else if (strcmp(userChoice, "paper") == 0 && strcmp(computerChoice, "scissors") == 0) {
        return "You lose!";
    } else if (strcmp(userChoice, "scissors") == 0 && strcmp(computerChoice, "rock") == 0) {
        return "You lose!";
    } else if (strcmp(userChoice, "scissors") == 0 && strcmp(computerChoice, "paper") == 0) {
        return "You win!";
    }
    return "Invalid input!";
}

int main() {
    char userChoice[10];
    printf("Enter your choice (rock, paper, or scissors): ");
    scanf("%s", userChoice);
    char* result = playRockPaperScissors(userChoice);
    printf("%s\n", result);
    return 0;
}
