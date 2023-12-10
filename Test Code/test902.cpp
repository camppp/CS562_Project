#include <unordered_map>

class InputManager {
private:
    std::unordered_map<int, int> vkeyStates; // Map to store virtual key states

public:
    void updateVKeyState(int vkeyIdentifier, int inputEvent) {
        if (vkeyStates.find(vkeyIdentifier) == vkeyStates.end()) {
            vkeyStates[vkeyIdentifier] = 0; // Initialize state to 0 if not present
        }

        int currentState = vkeyStates[vkeyIdentifier];

        if (inputEvent == VKEY_STATE_PRESSED) {
            if (currentState == VKEY_STATE_RELEASED) {
                vkeyStates[vkeyIdentifier] = VKEY_STATE_PRESSED; // Transition from released to pressed
            } else if (currentState == VKEY_STATE_PRESSED) {
                vkeyStates[vkeyIdentifier] = VKEY_STATE_HELD; // Transition from pressed to held
            }
        } else if (inputEvent == VKEY_STATE_RELEASED) {
            vkeyStates[vkeyIdentifier] = VKEY_STATE_RELEASED; // Set state to released
        }
    }

    int getVKeyState(int vkeyIdentifier) {
        if (vkeyStates.find(vkeyIdentifier) != vkeyStates.end()) {
            return vkeyStates[vkeyIdentifier];
        }
        return 0; // Return 0 if virtual key identifier not found
    }
};
