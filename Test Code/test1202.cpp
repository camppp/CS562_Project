#include <iostream>
#include <vector>
#include <mutex>

// Define the type for the final output
using FinalT = int;

// Define the type for the worker parameters
struct WorkerParams {
    int result;
    // Add any other relevant parameters here
};

class AggregatorT {
private:
    FinalT aggregatedValue;
    std::mutex mutex;

public:
    // Initialize the aggregator with an initial value for the aggregation process
    void set_aggregator(AggregatorT* ag, FinalT init_value) {
        std::lock_guard<std::mutex> lock(mutex);
        ag->aggregatedValue = init_value;
    }

    // Receive results from worker nodes and combine them to produce a final output
    void run(const WorkerParams& params) {
        std::lock_guard<std::mutex> lock(mutex);
        aggregatedValue += params.result;
    }

    // Get the final aggregated value
    FinalT getAggregatedValue() {
        std::lock_guard<std::mutex> lock(mutex);
        return aggregatedValue;
    }
};

int main() {
    // Create an instance of the aggregator
    AggregatorT aggregator;

    // Initialize the aggregator with an initial value
    aggregator.set_aggregator(&aggregator, 0);

    // Simulate worker nodes sending their results to the aggregator
    std::vector<WorkerParams> workerResults = {{10}, {20}, {30}};

    for (const auto& result : workerResults) {
        aggregator.run(result);
    }

    // Get the final aggregated value
    FinalT finalOutput = aggregator.getAggregatedValue();
    std::cout << "Final aggregated value: " << finalOutput << std::endl;

    return 0;
}
