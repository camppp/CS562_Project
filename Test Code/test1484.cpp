#include <iostream>

class Bullet {
private:
    // Member variables
    // ...

    bool isAlive;  // New member variable to track the bullet's state

public:
    // Constructor
    // ...

    // Methods
    void MoveUp();
    void MoveDown();
    bool Alive() const;
    void Revive();
    void Die();
};

// Implementation of the missing methods
void Bullet::Revive() {
    isAlive = true;
}

void Bullet::Die() {
    isAlive = false;
}

bool Bullet::Alive() const {
    return isAlive;
}

void Bullet::MoveUp() {
    if (pos.y < 150 && isAlive) {
        pos.y += speed;
    }
}

void Bullet::MoveDown() {
    if (pos.y > -725 && isAlive) {
        pos.y -= speed;
    }
}

int main() {
    // Create an instance of the Bullet class and test its functionality
    // ...
    return 0;
}
