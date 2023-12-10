#include <iostream>

// Define the Square class
class Square {
    // Define Square properties and methods
};

// Define the StateManager class
class StateManager {
private:
    Square* selectedSquare;

    StateManager() : selectedSquare(nullptr) {}  // Private constructor

public:
    static StateManager& getInstance()
    {
        static StateManager statemanager;
        return statemanager;
    }

    void setSelectedSquare(Square* square)
    {
        selectedSquare = square;
    }

    void removeSelectedSquare()
    {
        selectedSquare = nullptr;
    }

    Square* getSelectedSquare() const
    {
        return selectedSquare;
    }
};

int main() {
    // Create an instance of the StateManager
    StateManager& stateManager = StateManager::getInstance();

    // Create a Square object
    Square* square = new Square();

    // Set the selected square
    stateManager.setSelectedSquare(square);

    // Retrieve the selected square
    Square* retrievedSquare = stateManager.getSelectedSquare();
    if (retrievedSquare == square) {
        std::cout << "Selected square retrieved successfully." << std::endl;
    } else {
        std::cout << "Error: Failed to retrieve selected square." << std::endl;
    }

    // Remove the selected square
    stateManager.removeSelectedSquare();

    // Clean up memory
    delete square;

    return 0;
}
