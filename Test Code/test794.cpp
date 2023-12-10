#include <iostream>

// Define the input manager class (for demonstration purposes)
class InputManager {
public:
    void processInput() {
        std::cout << "Processing input" << std::endl;
    }
};

class Manager {
private:
    InputManager inputManager; // Private member for input manager object

public:
    /**
     * @brief Sets the input manager object
     * 
     * @param inputMgr The input manager object to be set
     */
    void setInputManager(const InputManager& inputMgr) {
        inputManager = inputMgr;
    }
};

int main() {
    Manager manager;
    InputManager inputMgr;

    manager.setInputManager(inputMgr); // Set the input manager object

    // For demonstration purposes
    manager.inputManager.processInput(); // Process input using the set input manager object

    return 0;
}
