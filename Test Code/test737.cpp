#include <iostream>

class Square {
public:
    Square(int x, int y) : x(x), y(y) {}
    int x, y;
};

class StateManager {
public:
    static StateManager* getInstance() {
        if (!instance) {
            instance = new StateManager();
        }
        return instance;
    }

    void setSelectedSquare(Square* square) {
        selectedSquare = square;
    }

    void removeSelectedSquare() {
        selectedSquare = nullptr;
    }

    Square* getSelectedSquare() const {
        return selectedSquare;
    }

private:
    StateManager() {}
    static StateManager* instance;
    Square* selectedSquare;
};

StateManager* StateManager::instance = nullptr;

int main() {
    StateManager* stateManager = StateManager::getInstance();

    // Set a selected square
    Square* square = new Square(1, 2);
    stateManager->setSelectedSquare(square);

    // Retrieve the selected square
    Square* selectedSquare = stateManager->getSelectedSquare();
    std::cout << "Selected square: " << selectedSquare->x << ", " << selectedSquare->y << std::endl;

    // Remove the selected square
    stateManager->removeSelectedSquare();

    return 0;
}
