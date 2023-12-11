#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>

class SecretNumber {
private:
    int secret;
    std::pair<int, int> range;
    int guessCount;

public:
    SecretNumber(int min, int max) : range(min, max), guessCount(0) {
        srand(time(0));
        secret = rand() % (max - min + 1) + min;
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
    SecretNumber sn(1, 100);
    int guess;

    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (sn.makeGuess(guess)) {
            std::cout << "Congratulations! You guessed the secret number." << std::endl;
            break;
        } else {
            std::cout << "Wrong guess. Try again." << std::endl;
        }
    }

    std::cout << "Number of guesses: " << sn.getGuessCount() << std::endl;

    return 0;
}