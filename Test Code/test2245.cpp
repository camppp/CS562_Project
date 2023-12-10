#include <vector>

class Listener {
public:
    virtual ~Listener() {}
};

class HookManager {
private:
    std::vector<Listener*> playerRunCommandListeners;
    std::vector<Listener*> userMessageListeners;

public:
    void AddPlayerRunCommandListener(Listener* listener) {
        playerRunCommandListeners.push_back(listener);
    }

    void RemovePlayerRunCommandListener(Listener* listener) {
        // Find and remove the listener from the vector
        playerRunCommandListeners.erase(
            std::remove(playerRunCommandListeners.begin(), playerRunCommandListeners.end(), listener),
            playerRunCommandListeners.end());
    }

    void AddUserMessageListener(Listener* listener) {
        userMessageListeners.push_back(listener);
    }

    void RemoveUserMessageListener(Listener* listener) {
        // Find and remove the listener from the vector
        userMessageListeners.erase(
            std::remove(userMessageListeners.begin(), userMessageListeners.end(), listener),
            userMessageListeners.end());
    }

    void UnloadAllListeners() {
        // Clear all the added listeners
        playerRunCommandListeners.clear();
        userMessageListeners.clear();
    }
};
