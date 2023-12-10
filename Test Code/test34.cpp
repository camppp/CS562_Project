#include <iostream>
#include <cstdlib>
#include <ctime>

class SecretNumber {
private:
    int secret;
    std::pair<int, int> range;
    int guessCount;

public:
    SecretNumber(int min, int max) : range(std::make_pair(min, max)), guessCount(0) {
        srand(static_cast<unsigned int>(time(nullptr)));
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
    SecretNumber secretNum(1, 100);
    int guess;
    std::pair<int, int> range = secretNum.getRange();

    std::cout << "Guess the secret number between " << range.first << " and " << range.second << std::endl;

    do {
        std::cin >> guess;
    } while (!secretNum.makeGuess(guess));

    std::cout << "Congratulations! You guessed the secret number in " << secretNum.getGuessCount() << " attempts." << std::endl;

    return 0;
}
