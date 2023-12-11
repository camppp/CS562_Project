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
    velocity.y += random_range(-2.0f, 2.0f);
    velocity.z += random_range(-2.0f, 2.0f);
    velocity.x += random_range(-1.0f, 1.0f);
    velocity.y *= Time::deltaTime * 5.0f;
    velocity.z *= Time::deltaTime * 5.0f;
    velocity.x *= Time::deltaTime * 5.0f;
}