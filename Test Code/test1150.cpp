#include <iostream>
#include <unordered_map>
#include <vector>

class NBestManager {
public:
    unsigned numFixedWeights;
    std::unordered_map<std::string, std::vector<std::vector<double>>> nbestScores;
    std::unordered_map<std::string, std::vector<std::string>> nbestAlignments;
    std::vector<double> lambdas;
    std::vector<double> lambdaDerivs;
    std::vector<double> prevLambdaDerivs;
    std::vector<double> prevLambdaDeltas;

    void storeNBestScores(const std::string& refString, const std::vector<std::vector<double>>& scores) {
        nbestScores[refString] = scores;
    }

    std::vector<std::vector<double>> retrieveNBestScores(const std::string& refString) {
        return nbestScores[refString];
    }

    void storeNBestAlignments(const std::string& refString, const std::vector<std::string>& alignments) {
        nbestAlignments[refString] = alignments;
    }

    std::vector<std::string> retrieveNBestAlignments(const std::string& refString) {
        return nbestAlignments[refString];
    }

    void updateScoreWeights(const std::vector<double>& newWeights) {
        lambdas = newWeights;
    }

    void calculateErrorDerivatives() {
        // Implementation to calculate error derivatives with respect to the score weights
        // Update lambdaDerivs array
    }

    void updatePrevLambdaDeltas() {
        prevLambdaDerivs = lambdaDerivs;
        // Calculate changes in score weights and update prevLambdaDeltas array
    }
};

int main() {
    // Example usage of the NBestManager class
    NBestManager manager;
    std::vector<std::vector<double>> scores = {{1.2, 3.4}, {5.6, 7.8}};
    manager.storeNBestScores("ref1", scores);
    std::vector<std::vector<double>> retrievedScores = manager.retrieveNBestScores("ref1");
    for (const auto& row : retrievedScores) {
        for (double score : row) {
            std::cout << score << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::string> alignments = {"alignment1", "alignment2"};
    manager.storeNBestAlignments("ref1", alignments);
    std::vector<std::string> retrievedAlignments = manager.retrieveNBestAlignments("ref1");
    for (const std::string& alignment : retrievedAlignments) {
        std::cout << alignment << " ";
    }
    std::cout << std::endl;

    std::vector<double> newWeights = {0.1, 0.2, 0.3};
    manager.updateScoreWeights(newWeights);

    manager.calculateErrorDerivatives();
    manager.updatePrevLambdaDeltas();

    return 0;
}
