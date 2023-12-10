#include <iostream>
#include <string>
#include <vector>

void PrintCRFAlphabets(const CRF& crf, std::ostream& out) {
    // Get the input, output, and weights alphabets
    const auto& inputAlphabet = crf.GetInputAlphabet();
    const auto& outputAlphabet = crf.GetOutputAlphabet();
    const auto& weightsAlphabet = crf.GetWeightsAlphabet();

    // Print the input alphabet
    out << "Input Alphabet: ";
    for (const auto& letter : inputAlphabet) {
        out << letter << " ";
    }
    out << std::endl;

    // Print the output alphabet
    out << "Output Alphabet: ";
    for (const auto& letter : outputAlphabet) {
        out << letter << " ";
    }
    out << std::endl;

    // Print the weights alphabet
    out << "Weights Alphabet: ";
    for (const auto& letter : weightsAlphabet) {
        out << letter << " ";
    }
    out << std::endl;
}
