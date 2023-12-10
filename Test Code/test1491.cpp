// model/normalized/model.cpp

#include "model/normalized/model.hpp"
#include <cmath>
#include <numeric>

NormalizedModel::NormalizedModel(const std::vector<double>& data) : originalData(data) {
    // Normalize the data
    double mean = calculateMean();
    double standardDeviation = calculateStandardDeviation();
    for (double value : originalData) {
        double normalizedValue = (value - mean) / standardDeviation;
        normalizedData.push_back(normalizedValue);
    }
}

std::vector<double> NormalizedModel::getNormalizedData() const {
    return normalizedData;
}

double NormalizedModel::calculateMean() const {
    double sum = std::accumulate(originalData.begin(), originalData.end(), 0.0);
    return sum / originalData.size();
}

double NormalizedModel::calculateStandardDeviation() const {
    double mean = calculateMean();
    double sum = 0.0;
    for (double value : originalData) {
        sum += (value - mean) * (value - mean);
    }
    double variance = sum / originalData.size();
    return std::sqrt(variance);
}
