#include <iostream>

class Weapon {
private:
    int durability;

public:
    // Constructor to initialize the durability
    Weapon(int initialDurability) : durability(initialDurability) {}

    // Method to decrease the durability by 5 units
    void useWeapon() {
        if (durability >= 5) {
            durability -= 5;
        } else {
            durability = 0;  // Ensure durability does not go below 0
        }
    }

    // Method to get the current durability
    int getDurability() {
        return durability;
    }
};

int main() {
    // Example usage of the Weapon class
    Weapon sword(50);  // Create a sword with initial durability of 50
    std::cout << "Initial durability: " << sword.getDurability() << std::endl;

    sword.useWeapon();  // Simulate using the sword
    std::cout << "Durability after use: " << sword.getDurability() << std::endl;

    sword.useWeapon();  // Simulate using the sword again
    std::cout << "Durability after another use: " << sword.getDurability() << std::endl;

    return 0;
}
