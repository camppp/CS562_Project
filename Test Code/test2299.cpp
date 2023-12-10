#include <iostream>
#include <random>

// Define the vec2 class representing a 2D vector
class vec2 {
public:
    float x, y;
    vec2(float _x, float _y) : x(_x), y(_y) {}
};

// Define the RandomFloat function to generate a random float within a specified range
float RandomFloat(float min, float max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(min, max);
    return dis(gen);
}

// Define the Particle class
class Particle {
public:
    vec2 m_direction;
    float m_alphaDelta;
    float m_sizeDelta;
    float m_rotationDelta;

    // Method to initialize the particle's properties based on the given code snippet
    void initializeProperties() {
        m_direction = vec2(RandomFloat(-4.0f, 4.0f), RandomFloat(4.0f, 10.0f));
        m_alphaDelta = RandomFloat(-0.15f, -0.09f);
        m_sizeDelta = RandomFloat(0.5f, 1.5f);
        m_rotationDelta = RandomFloat(-0.5f, 0.5f);
    }
};

int main() {
    // Create a Particle object and initialize its properties
    Particle particle;
    particle.initializeProperties();

    // Output the initialized properties
    std::cout << "Direction: (" << particle.m_direction.x << ", " << particle.m_direction.y << ")\n";
    std::cout << "Alpha Delta: " << particle.m_alphaDelta << "\n";
    std::cout << "Size Delta: " << particle.m_sizeDelta << "\n";
    std::cout << "Rotation Delta: " << particle.m_rotationDelta << "\n";

    return 0;
}
