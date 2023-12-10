#include <vector>

class NormalizedModel {
private:
    std::vector<double> originalData;
    std::vector<double> normalizedData;
public:
    NormalizedModel(const std::vector<double>& data) {
        originalData = data;
        normalizedData = normalize(data);
    }

    std::vector<double> getNormalizedData() const {
        return normalizedData;
    }

    double calculateMean() const {
        double sum = 0;
        for (double value : normalizedData) {
            sum += value;
        }
        return sum / normalizedData.size();
    }

    double calculateStandardDeviation() const {
        double mean = calculateMean();
        double sum = 0;
        for (double value : normalizedData) {
            sum += (value - mean) * (value - mean);
        }
        return sqrt(sum / (normalizedData.size() - 1));
    }

    std::vector<double> normalize(const std::vector<double>& data) {
        std::vector<double> normalizedData;
        for (double value : data) {
            normalizedData.push_back(value / data.size());
        }
        return normalizedData;
    }
};
