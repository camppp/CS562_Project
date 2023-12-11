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
        // Seed the random number generator with the current time
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        // Generate a random number within the specified range
        secret = rand() % (max - min + 1) + min;
    }

    bool makeGuess(int guess) {
        // Increment the count of guesses
        guessCount++;

        // Check if the guess is correct
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
    // Example usage
    SecretNumber secretNumber(1, 100);

    int guess;
    bool correctGuess = false;

    // Keep prompting the user for guesses until they guess correctly
    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        correctGuess = secretNumber.makeGuess(guess);

        if (!correctGuess) {
            std::cout << "Incorrect guess. Try again!" << std::endl;
        }

    } while (!correctGuess);

    std::cout << "Congratulations! You guessed the number in " << secretNumber.getGuessCount() << " attempts." << std::endl;

    return 0;
}