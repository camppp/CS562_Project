/**
 * Asd
 */
class Manager {
private:
    /**
     * @brief Objekt Správce vstupů 
     * 
     */
    InputManager inputManager;

public:
    // Add a public method to set the input manager object
    void setInputManager(InputManager inputManager) {
        this->inputManager = inputManager;
    }
};
