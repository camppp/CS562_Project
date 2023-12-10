#include <iostream>
#include <string>

class EngineLogger {
public:
    void engine_pre_step(double physics_time, double linear_momentum, double angular_momentum, double kinetic_energy, double position) {
        // Log the gathered information in a specific format
        std::string log_message = "Type: Engine Pre-Step\n";
        log_message += "Physics Time: " + std::to_string(physics_time) + "\n";
        log_message += "Linear Momentum: " + std::to_string(linear_momentum) + "\n";
        log_message += "Angular Momentum: " + std::to_string(angular_momentum) + "\n";
        log_message += "Kinetic Energy: " + std::to_string(kinetic_energy) + "\n";
        log_message += "Position: " + std::to_string(position) + "\n";
        std::cout << log_message;
    }
};
