#include <cstring>

void vcharCopyBounded(const char* newState, char* myState, int MAX_STATE_LEN) {
    if (newState) {
        int len = std::strlen(newState);
        if (len < MAX_STATE_LEN) {
            std::strcpy(myState, newState);
        } else {
            std::strncpy(myState, newState, MAX_STATE_LEN - 1);
            myState[MAX_STATE_LEN - 1] = '\0';  // Ensure null termination
        }
    } else {
        myState[0] = '\0';  // Set myState to an empty string
    }
}
