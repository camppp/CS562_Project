#include <iostream>

class Texture {
    // Define the Texture class as per the requirements of the game
};

class MazeDoor {
private:
    Texture* curObjTexture;
    bool open;

public:
    MazeDoor() : curObjTexture(nullptr), open(false) {}

    ~MazeDoor() {
        // Implement the destructor if necessary
    }

    void setTexture(Texture* newTexture) {
        curObjTexture = newTexture;
    }

    Texture* getTexture() {
        return curObjTexture;
    }

    bool isOpen() {
        return open;
    }
};

int main() {
    // Create an instance of MazeDoor
    MazeDoor door;

    // Create a Texture object
    Texture* doorTexture = new Texture(); // Assuming Texture class has a default constructor

    // Set the texture of the door
    door.setTexture(doorTexture);

    // Check if the door is open or closed
    if (door.isOpen()) {
        std::cout << "The door is open." << std::endl;
    } else {
        std::cout << "The door is closed." << std::endl;
    }

    // Clean up the allocated memory for doorTexture
    delete doorTexture;

    return 0;
}
