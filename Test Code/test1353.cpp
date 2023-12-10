bool validateInput(char arg1[], int arg2) {
    // Check if arg1 is a single character from the set {'c', 'o', 'i'}
    if (arg1.length() != 1 || !(arg1[0] == 'c' || arg1[0] == 'o' || arg1[0] == 'i')) {
        return false;
    }

    // Check if arg2 is a positive integer
    if (arg2 < 0) {
        return false;
    }

    return true;
}
