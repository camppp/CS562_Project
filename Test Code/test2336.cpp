#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>

std::vector<std::string> read2BitFile(const std::string& fileName) {
    std::ifstream file(fileName, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + fileName);
    }

    // Read header
    int sequenceCount;
    file.read(reinterpret_cast<char*>(&sequenceCount), sizeof(sequenceCount));
    std::vector<std::string> sequenceNames(sequenceCount);
    for (int i = 0; i < sequenceCount; ++i) {
        int nameLength;
        file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        sequenceNames[i].resize(nameLength);
        file.read(&sequenceNames[i][0], nameLength);
    }

    // Read encoded sequences
    std::vector<std::string> decodedSequences;
    for (const auto & seqName : sequenceNames) {
        int sequenceLength;
        file.read(reinterpret_cast<char*>(&sequenceLength), sizeof(sequenceLength));
        std::string encodedSequence;
        encodedSequence.resize(sequenceLength);
        file.read(&encodedSequence[0], sequenceLength);

        // Decode the 2-bit encoded sequence
        std::string decodedSequence;
        for (char c : encodedSequence) {
            std::bitset<2> bits(c);
            decodedSequence += "ACGT"[bits.to_ulong()];
        }
        decodedSequences.push_back(decodedSequence);
    }

    file.close();
    return decodedSequences;
}
