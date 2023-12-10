#include <iostream>

class Bullet {
private:
    // Member variables
    int pos_x, pos_y;
    int speed;
    bool alive;

public:
    // Constructor
    Bullet(int pos_x, int pos_y, int speed) : pos_x(pos_x), pos_y(pos_y), speed(speed), alive(true) {}

    // Methods
    void MoveUp() {
        if (pos_y < 150) {
            pos_y += speed;
        }
    }

    void MoveDown() {
        if (pos_y > -725) {
            pos_y -= speed;
        }
    }

    bool Alive() const {
        return alive;
    }

    void Revive() {
        alive = true;
    }

    void Die() {
        alive = false;
    }
};

int main() {
    // Create an instance of the Bullet class and test its functionality
    Bullet bullet(0, 0, 10);

    // Test the MoveUp method
    bullet.MoveUp();
    std::cout << "Bullet position: (" << bullet.pos_x << ", " << bullet.pos_y << ")" << std::endl;

    // Test the MoveDown method
    bullet.MoveDown();
    std::cout << "Bullet position: (" << bullet.pos_x << ", " << bullet.pos_y << ")" << std::endl;

    // Test the Alive method
    if (bullet.Alive()) {
        std::cout << "Bullet is alive" << std::endl;
    } else {
        std::cout << "Bullet is dead" << std::endl;
    }

    // Test the Revive method
    bullet.Revive();
    if (bullet.Alive()) {
        std::cout << "Bullet is alive" << std::endl;
    } else {
        std::cout << "Bullet is dead" << std::endl;
    }

    // Test the Die method
    bullet.Die();
    if (bullet.Alive()) {
        std::cout << "Bullet is alive" << std::endl;
    } else {
        std::cout << "Bullet is dead" << std::endl;
    }

    return 0;
}
