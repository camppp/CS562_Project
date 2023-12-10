std::string positBinaryRepresentation(int nbits, int es, double value) {
    // Convert the posit value to a binary representation
    std::string binaryRepresentation = std::bitset<nbits>(value).to_string();

    // Truncate the binary representation to the appropriate length
    binaryRepresentation = binaryRepresentation.substr(0, nbits - es);

    // Add the regime bits to the beginning of the binary representation
    binaryRepresentation = std::string(es, '0') + binaryRepresentation;

    return binaryRepresentation;
}
