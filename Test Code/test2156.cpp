#include <cmath>

class TrajectoryBangbangWithDrag {
public:
    float beta() const {
        // Implement the beta function to return the drag coefficient to mass ratio
        // Example:
        return 0.5f;  // Replace with actual implementation
    }

    float mu() const {
        // Implement the mu function to return the coefficient of friction
        // Example:
        return 0.3f;  // Replace with actual implementation
    }

    float terminal_velocity() const {
        // Implement the terminal_velocity function to return the terminal velocity of the object
        // Example:
        return 10.0f;  // Replace with actual implementation
    }

    float time_to_accel() {
        return std::log((1 + beta()) / (1 - beta())) / 2.0f / mu() / terminal_velocity();
    }

    float time_to_decel() {
        return std::atan(beta()) / mu() / terminal_velocity();
    }
};
