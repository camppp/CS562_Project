#include <iostream>
#include <memory>
#include "MLCMST_Solver.h"
#include "Star.h"
#include "MLCCNetwork.h"
#include "MLCST.h"

class MLCMST_Improver {
public:
    MLCMST_Improver();
    MLCMST_Improver(std::unique_ptr<MLCMST_Solver> init_solver);
    network::MLCST run(const network::MLCCNetwork &mlcc_network);

private:
    std::unique_ptr<MLCMST_Solver> init_solver_;
};

MLCMST_Improver::MLCMST_Improver() : MLCMST_Improver(std::make_unique<Star>()) {
}

MLCMST_Improver::MLCMST_Improver(std::unique_ptr<MLCMST_Solver> init_solver) : init_solver_(std::move(init_solver)) {
}

network::MLCST MLCMST_Improver::run(const network::MLCCNetwork &mlcc_network) {
    // Use the initial solver to obtain an initial MLCMST solution
    network::MLCST initial_solution = init_solver_->solve(mlcc_network);

    // Implement the algorithm or approach to improve the initial solution
    network::MLCST improved_solution = improveSolution(initial_solution);

    return improved_solution;
}

int main() {
    // Create an instance of MLCMST_Improver
    MLCMST_Improver improver;

    // Create a sample MLCCNetwork
    network::MLCCNetwork mlcc_network = createSampleNetwork();

    // Obtain the improved MLCST solution
    network::MLCST improved_solution = improver.run(mlcc_network);

    // Output the improved solution
    std::cout << "Improved MLCST solution: " << improved_solution << std::endl;

    return 0;
}
