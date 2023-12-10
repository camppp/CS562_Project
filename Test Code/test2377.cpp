class Weapon {
private:
    int durability;

public:
    Weapon(int initialDurability) {
        durability = initialDurability;
    }

    void useWeapon() {
        durability -= 5;
    }

    int getDurability() {
        return durability;
    }
};
