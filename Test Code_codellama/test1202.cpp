#include <iostream>
#include <vector>

template <typename FinalT>
class AggregatorT {
public:
    AggregatorT(FinalT init_value) : final_value(init_value) {}

    void set_aggregator(AggregatorT* ag, FinalT init_value) {
        this->final_value = init_value;
    }

    void run(const WorkerParams& params) {
        // Combine the results from the worker nodes
        final_value = combine_results(params);
    }

private:
    FinalT final_value;

    FinalT combine_results(const WorkerParams& params) {
        // Implement the logic to combine the results from the worker nodes
        // Here, we simply add the results together
        FinalT result = final_value;
        for (const auto& param : params) {
            result += param.result;
        }
        return result;
    }
};
