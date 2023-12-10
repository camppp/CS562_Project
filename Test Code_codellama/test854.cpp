#include <iostream>

class phys_props {
public:
    float mass;
    float friction;
    float restitution;

    phys_props(float m, float f, float r) : mass(m), friction(f), restitution(r) {}
};

class physics3d {
public:
    static phys_props static_props(float friction, float restitution) {
        return phys_props(0, friction, restitution);
    }
};

int main() {
    phys_props props = physics3d::static_props(0.5, 0.8);
    std::cout << "Friction: " << props.friction << ", Restitution: " << props.restitution << std::endl;
    return 0;
}
