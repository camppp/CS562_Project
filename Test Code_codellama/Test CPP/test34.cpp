#include <iostream>
#include <cstdlib>
#include <ctime>

class SecretNumber {
private:
    int secret;
    std::pair<int, int> range;
    int guessCount;

public:
    SecretNumber(int min, int max) {
        range = std::make_pair(min, max);
        secret = std::rand() % (max - min + 1) + min;
        guessCount = 0;
    }

    bool makeGuess(int guess) {
        guessCount++;
        return guess == secret;
    }

    std::pair<int, int> getRange() {
        return range;
    }

    int getGuessCount() {
        return guessCount;
    }
};

int main() {
    SecretNumber secretNumber(1, 10);
    std::cout << "Secret number: " << secretNumber.secret << std::endl;
    std::cout << "Range: " << secretNumber.getRange().first << " to " << secretNumber.getRange().second << std::endl;
    std::cout << "Guess count: " << secretNumber.getGuessCount() << std::endl;

    int guess;
    std::cout << "Enter a guess: ";
    std::cin >> guess;
    bool isCorrect = secretNumber.makeGuess(guess);
    if (isCorrect) {
        std::cout << "Correct!" << std::endl;
    } else {
        std::cout << "Incorrect" << std::endl;
    }

    return 0;
}
