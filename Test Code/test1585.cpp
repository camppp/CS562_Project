#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* playRockPaperScissors(char* userChoice) {
    const char* choices[] = {"rock", "paper", "scissors"};
    int computerChoice = rand() % 3;  // Generate a random choice for the computer

    if (strcmp(userChoice, choices[computerChoice]) == 0) {
        return "It's a tie!";
    } else if ((strcmp(userChoice, "rock") == 0 && strcmp(choices[computerChoice], "scissors") == 0) ||
               (strcmp(userChoice, "paper") == 0 && strcmp(choices[computerChoice], "rock") == 0) ||
               (strcmp(userChoice, "scissors") == 0 && strcmp(choices[computerChoice], "paper") == 0)) {
        return "You win!";
    } else {
        return "You lose!";
    }
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    char userChoice[10];
    printf("Enter your choice (rock, paper, or scissors): ");
    scanf("%s", userChoice);
    char* result = playRockPaperScissors(userChoice);
    printf("%s\n", result);
    return 0;
}
