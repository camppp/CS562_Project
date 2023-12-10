python
def guessLetter(hiddenWord, guessedLetters, guess):
    if guess in guessedLetters:
        return "Warning: Letter already guessed!"
    else:
        guessedLetters.append(guess)
        current_state = ""
        for letter in hiddenWord:
            if letter in guessedLetters:
                current_state += letter + " "
            else:
                current_state += "_ "
        return current_state.strip()
