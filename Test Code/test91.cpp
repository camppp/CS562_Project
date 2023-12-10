#include <iostream>
#include <random>

struct Vector3 {
    float x, y, z;
};

float random_range(float min, float max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(min, max);
    return dis(gen);
}

void updateParticleVelocity(Vector3& velocity) {
    velocity.x += random_range(-2.0f, 2.0f);
    velocity.y += random_range(-2.0f, 2.0f);
    velocity.z += random_range(-1.0f, 1.0f);
    velocity.x *= 0.02f * 5.0f;
    velocity.y *= 0.02f * 5.0f;
    velocity.z *= 0.02f * 5.0f;
}

int main() {
    Vector3 velocity = {1.0f, 2.0f, 3.0f};
    float deltaTime = 0.02f;
    updateParticleVelocity(velocity);
    std::cout << "Updated velocity = {" << velocity.x << "f, " << velocity.y << "f, " << velocity.z << "f}" << std::endl;
    return 0;
}
