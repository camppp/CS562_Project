#include <iostream>

// Define the Vector2 class from the UnityEngine library
namespace UnityEngine {
    struct Vector2 {
        float x, y;
    };
}

class VectorManager {
private:
    UnityEngine::Vector2 moveVector;

public:
    void SetMoveVector(float x, float y) {
        moveVector.x = x;
        moveVector.y = y;
    }

    UnityEngine::Vector2 GetMoveVector() {
        return moveVector;
    }
};

int main() {
    // Create an instance of VectorManager
    VectorManager manager;

    // Set the moveVector using SetMoveVector method
    manager.SetMoveVector(3.5f, 2.8f);

    // Retrieve the moveVector using GetMoveVector method
    UnityEngine::Vector2 vector = manager.GetMoveVector();

    // Output the retrieved moveVector
    std::cout << "Move Vector: (" << vector.x << ", " << vector.y << ")" << std::endl;

    return 0;
}
