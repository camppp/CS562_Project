#include <vector>

class Memory {
private:
    std::vector<std::vector<double>> datasets;

public:
    // Adds a new dataset to the memory
    void add_dataset(const std::vector<double>& numbers) {
        datasets.push_back(numbers);
    }

    // Retrieves datasets from memory for processing and returns them as a vector of doubles
    std::vector<double> do_run_generation() {
        std::vector<double> result;
        for (const auto& dataset : datasets) {
            result.insert(result.end(), dataset.begin(), dataset.end());
        }
        return result;
    }
};
