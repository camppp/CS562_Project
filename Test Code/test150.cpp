#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Define the JsonReporter class
class JsonReporter {
public:
    // Constructor
    JsonReporter() {}

    // Destructor
    ~JsonReporter() {}

    // Method to convert benchmarking data into JSON format
    json convertToJSON(const std::vector<double>& data) {
        json jsonOutput;
        jsonOutput["data"] = data;
        jsonOutput["mean"] = calculateMean(data);
        jsonOutput["median"] = calculateMedian(data);
        jsonOutput["standard_deviation"] = calculateStandardDeviation(data);
        return jsonOutput;
    }

private:
    // Method to calculate the mean of the data
    double calculateMean(const std::vector<double>& data) {
        double sum = 0.0;
        for (const auto& value : data) {
            sum += value;
        }
        return sum / data.size();
    }

    // Method to calculate the median of the data
    double calculateMedian(const std::vector<double>& data) {
        std::vector<double> sortedData = data;
        std::sort(sortedData.begin(), sortedData.end());
        size_t size = sortedData.size();
        if (size % 2 == 0) {
            return (sortedData[size / 2 - 1] + sortedData[size / 2]) / 2.0;
        } else {
            return sortedData[size / 2];
        }
    }

    // Method to calculate the standard deviation of the data
    double calculateStandardDeviation(const std::vector<double>& data) {
        double mean = calculateMean(data);
        double sum = 0.0;
        for (const auto& value : data) {
            sum += (value - mean) * (value - mean);
        }
        return std::sqrt(sum / data.size());
    }
};

int main() {
    // Example usage of the JsonReporter class
    std::vector<double> benchmarkData = {10.5, 15.2, 20.8, 18.6, 12.3};
    JsonReporter jsonReporter;
    json jsonOutput = jsonReporter.convertToJSON(benchmarkData);
    std::cout << jsonOutput.dump(4) << std::endl;  // Output the JSON with indentation
    return 0;
}
