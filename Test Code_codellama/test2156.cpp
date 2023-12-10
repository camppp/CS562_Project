#include <cmath>

class TrajectoryBangbangWithDrag {
public:
    TrajectoryBangbangWithDrag(float beta, float mu, float terminal_velocity)
        : beta_(beta), mu_(mu), terminal_velocity_(terminal_velocity) {}

    float time_to_accel() {
        return log((1 + beta_) / (1 - beta_)) / (2 * mu_ * terminal_velocity_);
    }

    float time_to_decel() {
        return arctan(beta_) / (mu_ * terminal_velocity_);
    }

private:
    float beta_;
    float mu_;
    float terminal_velocity_;
};
