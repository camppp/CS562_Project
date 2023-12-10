int strStr(string haystack, string needle) {
    // Construct the DFA for the pattern
    DFA dfa(needle);

    // Initialize the current state of the DFA
    int currentState = 0;

    // Iterate over the characters in the text
    for (int i = 0; i < haystack.size(); i++) {
        // Get the next character in the text
        char c = haystack[i];

        // Get the next state of the DFA
        currentState = dfa.nextState(currentState, c);

        // If the DFA accepts the current state, we have found the pattern
        if (dfa.accepts(currentState)) {
            return i - needle.size() + 1;
        }
    }

    // If the DFA does not accept any state, we have not found the pattern
    return -1;
}
