#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class NBestManager {
public:
    NBestManager(unsigned int numFixedWeights) : numFixedWeights(numFixedWeights) {}

    void storeNBestScores(const std::string& refString, const std::vector<std::vector<double>>& nBestScores) {
        nbestScores[refString] = nBestScores;
    }

    std::vector<std::vector<double>> retrieveNBestScores(const std::string& refString) {
        return nbestScores[refString];
    }

    void storeNBestAlignments(const std::string& refString, const WordMesh& nBestAlignments) {
        nbestAlignments[refString] = nBestAlignments;
    }

    WordMesh retrieveNBestAlignments(const std::string& refString) {
        return nbestAlignments[refString];
    }

    void updateScoreWeights(const std::vector<double>& newLambdas) {
        lambdas = newLambdas;
    }

    void calculateErrorDerivatives() {
        for (int i = 0; i < numFixedWeights; i++) {
            lambdaDerivs[i] = 0;
            for (int j = 0; j < nbestScores.size(); j++) {
                lambdaDerivs[i] += nbestScores[j][i] * (lambdas[i] - prevLambdas[i]);
            }
        }
    }

    void updatePrevLambdaDeltas() {
        for (int i = 0; i < numFixedWeights; i++) {
            prevLambdaDeltas[i] = lambdaDerivs[i];
        }
    }

private:
    unsigned int numFixedWeights;
    std::unordered_map<std::string, std::vector<std::vector<double>>> nbestScores;
    std::unordered_map<std::string, WordMesh> nbestAlignments;
    std::vector<double> lambdas;
    std::vector<double> lambdaDerivs;
    std::vector<double> prevLambdaDeltas;
};
