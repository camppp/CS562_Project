void vcharCopyBounded(char* newState, char* myState, int MAX_STATE_LEN) {
    if (newState != nullptr) {
        // Copy the state to the buffer, ensuring that the length does not exceed MAX_STATE_LEN - 1
        strncpy(myState, newState, MAX_STATE_LEN - 1);
        // Add the null terminator
        myState[MAX_STATE_LEN - 1] = '\0';
    } else {
        // Set the buffer to an empty string
        myState[0] = '\0';
    }
}
