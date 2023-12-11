string guessLetter(string hiddenWord, list<string> guessedLetters, string guess) {
    // Check if the guessed letter has already been guessed
    if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
        return "Warning: Letter already guessed!";
    }

    // Replace the underscores with the guessed letter
    for (int i = 0; i < hiddenWord.length(); i++) {
        if (hiddenWord[i] == guess) {
            guessedLetters.push_back(guess);
            hiddenWord[i] = guess;
        }
    }

    // Return the current state of the word
    return hiddenWord;
}
