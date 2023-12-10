#include <iostream>
#include <vector>

// Classes for DNA components
class ADNDoubleStrand {
public:
    std::vector<ADNSingleStrand*> singleStrands;
};

class ADNSingleStrand {
public:
    std::vector<ADNBaseSegment*> baseSegments;
};

class ADNBaseSegment {
public:
    ADNNucleotide* nucleotide;
};

class ADNNucleotide {
public:
    ADNAtom* atom;
};

class ADNAtom {
public:
    // Atom properties
};

// Registration functions
void registerDoubleStrand(ADNDoubleStrand* doubleStrand) {
    // Add doubleStrand to the list of double strands
}

void registerBaseSegmentEnd(ADNBaseSegment* baseSegment) {
    // Add baseSegment to the list of base segments
}

void registerSingleStrand(ADNSingleStrand* singleStrand) {
    // Add singleStrand to the list of single strands
}

void registerNucleotide(ADNNucleotide* nucleotide) {
    // Add nucleotide to the list of nucleotides
}

void registerAtom(ADNAtom* atom) {
    // Add atom to the list of atoms
}

int main() {
    // Create DNA components
    ADNDoubleStrand* doubleStrand = new ADNDoubleStrand();
    ADNSingleStrand* singleStrand = new ADNSingleStrand();
    ADNBaseSegment* baseSegment = new ADNBaseSegment();
    ADNNucleotide* nucleotide = new ADNNucleotide();
    ADNAtom* atom = new ADNAtom();

    // Register DNA components
    registerDoubleStrand(doubleStrand);
    registerBaseSegmentEnd(baseSegment);
    registerSingleStrand(singleStrand);
    registerNucleotide(nucleotide);
    registerAtom(atom);

    // Print the list of registered DNA components
    std::cout << "Double strands: ";
    for (auto doubleStrand : doubleStrands) {
        std::cout << doubleStrand->singleStrands.size() << " ";
    }
    std::cout << std::endl;

    std::cout << "Single strands: ";
    for (auto singleStrand : singleStrands) {
        std::cout << singleStrand->baseSegments.size() << " ";
    }
    std::cout << std::endl;

    std::cout << "Base segments: ";
    for (auto baseSegment : baseSegments) {
        std::cout << baseSegment->nucleotide->atom->getAtomName() << " ";
    }
    std::cout << std::endl;

    std::cout << "Nucleotides: ";
    for (auto nucleotide : nucleotides) {
        std::cout << nucleotide->atom->getAtomName() << " ";
    }
    std::cout << std::endl;

    std::cout << "Atoms: ";
    for (auto atom : atoms) {
        std::cout << atom->getAtomName() << " ";
    }
    std::cout << std::endl;

    return 0;
}
