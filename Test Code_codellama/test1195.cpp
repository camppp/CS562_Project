#include <SFML/Graphics.hpp>

class LavaFloor {
 public:
  LavaFloor() : is_ignited_(false), heat_emission_rate_(0.0f) {}

  void SetPosition(float x, float y) {
    floor_shape_.setPosition(x, y);
  }

  void Update(float delta_time) {
    if (is_ignited_) {
      heat_emission_rate_ += delta_time * 0.1f;
      if (heat_emission_rate_ > 1.0f) {
        heat_emission_rate_ = 1.0f;
      }
    } else {
      heat_emission_rate_ = 0.0f;
    }
  }

  void Ignite() {
    is_ignited_ = true;
  }

  void Extinguish() {
    is_ignited_ = false;
  }

 private:
  sf::RectangleShape floor_shape_;
  bool is_ignited_;
  float heat_emission_rate_;
};
