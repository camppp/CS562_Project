#include <UnityEngine>

class MoveVectorManager {
private:
    Vector2 moveVector;

public:
    void SetMoveVector(float x, float y) {
        moveVector.x = x;
        moveVector.y = y;
    }

    Vector2 GetMoveVector() {
        return moveVector;
    }
};
