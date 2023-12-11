char readKey() {
    // Read the keypad input
    char key = readKeypad();

    // Check if the key is a special action
    if (key == 'ENTER') {
        return key;
    } else if (key == 'CANCEL') {
        return key;
    } else if (key == 'UP') {
        return key;
    } else if (key == 'DOWN') {
        return key;
    } else if (key == 'LEFT') {
        return key;
    } else if (key == 'RIGHT') {
        return key;
    }

    // If the key is not a special action, return the corresponding character
    return key;
}
