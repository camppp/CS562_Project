#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> read2BitFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Error: unable to open file " << fileName << std::endl;
        return {};
    }

    // Read the header
    std::string header;
    std::getline(file, header);
    if (header.empty()) {
        std::cerr << "Error: file " << fileName << " is empty" << std::endl;
        return {};
    }

    // Parse the header
    std::vector<std::string> sequenceNames;
    int sequenceCount = 0;
    for (const auto& line : header) {
        if (line == "Sequence Count:") {
            sequenceCount = std::stoi(line.substr(line.find(':') + 1));
        } else if (line == "Sequence Names:") {
            sequenceNames = line.substr(line.find(':') + 1).split(',');
        }
    }

    // Read the encoded sequences
    std::vector<std::string> sequences;
    for (int i = 0; i < sequenceCount; i++) {
        std::string sequence;
        std::getline(file, sequence);
        if (sequence.empty()) {
            std::cerr << "Error: file " << fileName << " is missing sequence " << i << std::endl;
            return {};
        }
        sequences.push_back(sequence);
    }

    // Decode the sequences
    std::vector<std::string> decodedSequences;
    for (const auto& sequence : sequences) {
        std::string decodedSequence;
        for (int i = 0; i < sequence.size(); i += 2) {
            char base = sequence[i];
            if (base == '0') {
                decodedSequence += 'A';
            } else if (base == '1') {
                decodedSequence += 'C';
            } else if (base == '2') {
                decodedSequence += 'G';
            } else if (base == '3') {
                decodedSequence += 'T';
            } else {
                std::cerr << "Error: invalid base " << base << " in sequence " << sequence << std::endl;
                return {};
            }
        }
        decodedSequences.push_back(decodedSequence);
    }

    return decodedSequences;
}
