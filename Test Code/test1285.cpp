#include <iostream>

// Definition of the ProcfsMetricsProvider class
class ProcfsMetricsProvider {
public:
    ProcfsMetricsProvider(int) {}
    void getTaskStats(::taskstats&) {}
};

// Definition of the taskstats struct
struct taskstats {
    long cpu_run_virtual_total;
};

// Function to calculate the average CPU time consumed per iteration
double calculateAverageCpuTime(const long start_cpu_time, size_t num_iterations, ProcfsMetricsProvider& stats_provider) {
    ::taskstats stats;
    stats_provider.getTaskStats(stats);

    const auto initial_cpu_time = stats.cpu_run_virtual_total;
    for (size_t i = 0; i < num_iterations; ++i) {
        stats_provider.getTaskStats(stats);
    }

    const auto final_cpu_time = stats.cpu_run_virtual_total;
    return static_cast<double>(final_cpu_time - initial_cpu_time) / num_iterations;
}

int main() {
    // Example usage
    ProcfsMetricsProvider stats_provider(0);
    const long start_cpu_time = 0;  // Replace with actual initial CPU time
    size_t num_iterations = 100;    // Replace with actual number of iterations
    double avg_cpu_time = calculateAverageCpuTime(start_cpu_time, num_iterations, stats_provider);
    std::cout << "Average CPU time consumed per iteration: " << avg_cpu_time << std::endl;
    return 0;
}
