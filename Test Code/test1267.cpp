#include <rr_common/planning/annealing_optimizer.h>
#include <rr_common/planning/planning_utils.h>
#include <parameter_assertions/assertions.h>

class SimulatedAnnealingOptimizer : public Optimizer {
public:
    Solution optimize(const Solution& initial_solution) {
        Solution current_solution = initial_solution;
        double temperature = 1.0;
        while (temperature > 0.001) {
            Solution new_solution = current_solution;
            // Perform a random search around the current solution
            for (int i = 0; i < 10; i++) {
                int random_index = rand() % current_solution.size();
                new_solution[random_index] = current_solution[random_index] + 0.1 * (rand() % 2 - 0.5);
            }
            // Calculate the acceptance probability based on the current solution and the new solution
            double acceptance_probability = acceptance_probability(current_solution, new_solution, temperature);
            // Accept the new solution with the given probability
            if (acceptance_probability > 0.5) {
                current_solution = new_solution;
            }
            // Cool the temperature
            cooling_schedule(temperature);
        }
        return current_solution;
    }

    double acceptance_probability(const Solution& current_solution, const Solution& new_solution, double temperature) {
        // Calculate the difference between the current solution and the new solution
        double difference = 0.0;
        for (int i = 0; i < current_solution.size(); i++) {
            difference += pow(current_solution[i] - new_solution[i], 2.0);
        }
        // Calculate the acceptance probability based on the difference and the temperature
        double acceptance_probability = exp(-difference / temperature);
        return acceptance_probability;
    }

    void cooling_schedule(double& temperature) {
        // Decrease the temperature by a factor of 0.95
        temperature *= 0.95;
    }
};
