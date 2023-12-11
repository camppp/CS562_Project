#include <iostream>
#include <cstdlib>

int rollDiceGame() {
    int score = 0;
    int roll = 0;

    while (true) {
        roll = rand() % 6 + 1;
        if (roll == 1) {
            break;
        }
        score += roll;
        std::cout << "Roll: " << roll << ", Total score: " << score << std::endl;
    }

    std::cout << "Final score: " << score << std::endl;
    return score;
}
