#include <iostream>
#include <string>
#include <unordered_map>

// Advection solver classes
class AdvectionSolver {
public:
    void setSolverType(const std::string& type) {
        // Implementation to set advection solver based on type
        std::cout << "Advection solver set to: " << type << std::endl;
    }
};

// Diffusion solver classes
class DiffusionSolver {
public:
    void setSolverType(const std::string& type) {
        // Implementation to set diffusion solver based on type
        std::cout << "Diffusion solver set to: " << type << std::endl;
    }
};

class SolverSelection {
public:
    static void SetAdvectionSolver(std::unordered_map<std::string, std::string>& settings, AdvectionSolver* advSolver, const std::string& advectionType) {
        // Get advection type from settings and set the advection solver
        std::string advectionSetting = settings["solver/advection/type"];
        advSolver->setSolverType(advectionSetting);
    }

    static void SetDiffusionSolver(std::unordered_map<std::string, std::string>& settings, DiffusionSolver* difSolver, const std::string& diffusionType) {
        // Get diffusion type from settings and set the diffusion solver
        std::string diffusionSetting = settings["solver/diffusion/type"];
        difSolver->setSolverType(diffusionSetting);
    }
};

int main() {
    // Example usage
    std::unordered_map<std::string, std::string> settings = {
        {"solver/advection/type", "Upwind"},
        {"solver/diffusion/type", "Implicit"}
    };

    AdvectionSolver adv_vel;
    DiffusionSolver dif_vel;

    SolverSelection::SetAdvectionSolver(settings, &adv_vel, settings["solver/advection/type"]);
    SolverSelection::SetDiffusionSolver(settings, &dif_vel, settings["solver/diffusion/type"]);

    return 0;
}
