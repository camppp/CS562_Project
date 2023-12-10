int countUnclosedBraces(string input) {
    int count = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '}') {
            if (i == 0 || input[i - 1] != '{') {
                count++;
            }
        }
    }
    return count;
}
