#include <SFML/Graphics.hpp>

class LavaFloor {
public:
    void SetPosition(float x, float y) {
        floor_shape_.setPosition(x, y);
    }

    void Update(float delta_time) {
        if (is_ignited_) {
            // Simulate heat emission based on elapsed time and emission rate
            // Example: floor_shape_.emitHeat(heat_emission_rate_ * delta_time);
        }
    }

    void Ignite() {
        is_ignited_ = true;
        // Perform any additional actions when ignited
    }

    void Extinguish() {
        is_ignited_ = false;
        // Perform any additional actions when extinguished
    }

private:
    sf::RectangleShape floor_shape_;
    bool is_ignited_ = false;
    float heat_emission_rate_ = 1.0f;
};
