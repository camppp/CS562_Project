#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Atom {
public:
    Atom(int atomicNumber, float x, float y, float z) : atomicNumber(atomicNumber), x(x), y(y), z(z) {}

    int getAtomicNumber() const { return atomicNumber; }
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }

private:
    int atomicNumber;
    float x, y, z;
};

std::vector<Atom> parseInputFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    std::vector<Atom> atoms;

    while (inputFile) {
        std::string line;
        std::getline(inputFile, line);

        if (line.empty()) {
            continue;
        }

        std::stringstream lineStream(line);
        std::string atomicSymbol;
        float x, y, z;

        lineStream >> atomicSymbol >> x >> y >> z;

        if (atomicSymbol.empty() || x < 0 || y < 0 || z < 0) {
            std::cerr << "Invalid input on line " << lineStream.tellg() << ": " << line << std::endl;
            continue;
        }

        int atomicNumber = getAtomicNumber(atomicSymbol);
        if (atomicNumber == -1) {
            std::cerr << "Invalid atomic symbol on line " << lineStream.tellg() << ": " << atomicSymbol << std::endl;
            continue;
        }

        atoms.push_back(Atom(atomicNumber, x, y, z));
    }

    return atoms;
}

int getAtomicNumber(const std::string& atomicSymbol) {
    if (atomicSymbol == "H") {
        return 1;
    } else if (atomicSymbol == "He") {
        return 2;
    } else if (atomicSymbol == "Li") {
        return 3;
    } else if (atomicSymbol == "Be") {
        return 4;
    } else if (atomicSymbol == "B") {
        return 5;
    } else if (atomicSymbol == "C") {
        return 6;
    } else if (atomicSymbol == "N") {
        return 7;
    } else if (atomicSymbol == "O") {
        return 8;
    } else if (atomicSymbol == "F") {
        return 9;
    } else if (atomicSymbol == "Ne") {
        return 10;
    } else if (atomicSymbol == "Na") {
        return 11;
    } else if (atomicSymbol == "Mg") {
        return 12;
    } else if (atomicSymbol == "Al") {
        return 13;
    } else if (atomicSymbol == "Si") {
        return 14;
    } else if (atomicSymbol == "P") {
        return 15;
    } else if (atomicSymbol == "S") {
        return 16;
    } else if (atomicSymbol == "Cl") {
        return 17;
    } else if (atomicSymbol == "Ar") {
        return 18;
    } else if (atomicSymbol == "K") {
        return 19;
    } else if (atomicSymbol == "Ca") {
        return 20;
    } else if (atomicSymbol == "Sc") {
        return 21;
    } else if (atomicSymbol == "Ti") {
        return 22;
    } else if (atomicSymbol == "V") {
        return 23;
    } else if (atomicSymbol == "Cr") {
        return 24;
    } else if (atomicSymbol == "Mn") {
        return 25;
    } else if (atomicSymbol == "Fe") {
        return 26;
    } else if (atomicSymbol == "Co") {
        return 27;
    } else if (atomicSymbol == "Ni") {
        return 28;
    } else if (atomicSymbol == "Cu") {
        return 29;
    } else if (atomicSymbol == "Zn") {
        return 30;
    } else if (atomicSymbol == "Ga") {
        return 31;
    } else if (atomicSymbol == "Ge") {
        return 32;
    } else if (atomicSymbol == "As") {
        return 33;
    } else if (atomicSymbol == "Se") {
        return 34;
    } else if (atomicSymbol == "Br") {
        return 35;
    } else if (atomicSymbol == "Kr") {
        return 36;
    } else if (atomicSymbol == "Rb") {
        return 37;
    } else if (atomicSymbol == "Sr") {
        return 38;
    } else if (atomicSymbol == "Y") {
        return 39;
    } else if (atomicSymbol == "Zr") {
        return 40;
    } else if (atomicSymbol == "Nb") {
        return 41;
    } else if (atomicSymbol == "Mo") {
        return 42;
    } else if (atomicSymbol == "Tc") {
        return 43;
    } else if (atomicSymbol == "Ru") {
        return 44;
    } else if (atomicSymbol == "Rh") {
        return 45;
    } else if (atomicSymbol == "Pd") {
        return 46;
    } else if (atomicSymbol == "Ag") {
        return 47;
    } else if (atomicSymbol == "Cd") {
        return 48;
    } else if (atomicSymbol == "In") {
        return 49;
    } else if (atomicSymbol == "Sn") {
        return 50;
    } else if (atomicSymbol == "Sb") {
        return 51;
    } else if (atomicSymbol == "Te") {
        return 52;
    } else if (atomicSymbol == "I") {
        return 53;
    } else if (atomicSymbol == "Xe") {
        return 54;
    } else if (atomicSymbol == "Cs") {
        return 55;
    } else if (atomicSymbol == "Ba") {
        return 56;
    } else if (atomicSymbol == "La") {
        return 57;
    } else if (atomicSymbol == "Ce") {
        return 58;
    } else if (atomicSymbol == "Pr") {
        return 59;
    } else if (atomicSymbol == "Nd") {
        return 60;
    } else if (atomicSymbol == "Pm") {
        return 61;
    } else if (atomicSymbol == "Sm") {
        return 62;
    } else if (atomicSymbol == "Eu") {
        return 63;
    } else if (atomicSymbol == "Gd") {
        return 64;
    } else if (atomicSymbol == "Tb") {
        return 65;
    } else if (atomicSymbol == "Dy") {
        return 66;
    } else if (atomicSymbol == "Ho") {
        return 67;
    } else if (atomicSymbol == "Er") {
        return 68;
    } else if (atomicSymbol == "Tm") {
        return 69;
    } else if (atomicSymbol == "Yb") {
        return 70;
    } else if (atomicSymbol == "Lu") {
        return 71;
    } else if (atomicSymbol == "Hf") {
        return 72;
    } else if (atomicSymbol == "Ta") {
        return 73;
    } else if (atomicSymbol == "W") {
        return 74;
    } else if (atomicSymbol == "Re") {
        return 75;
    } else if (atomicSymbol == "Os") {
        return 76;
    } else if (atomicSymbol == "Ir") {
        return 77;
    } else if (atomicSymbol == "Pt") {
        return 78;
    } else if (atomicSymbol == "Au") {
        return 79;
    } else if (atomicSymbol == "Hg") {
        return 80;
    } else if (atomicSymbol == "Tl") {
        return 81;
    } else if (atomicSymbol == "Pb") {
        return 82;
    } else if (atomicSymbol == "Bi") {
        return 83;
    } else if (atomicSymbol == "Po") {
        return 84;
    } else if (atomicSymbol == "At") {
        return 85;
    } else if (atomicSymbol == "Rn") {
        return 86;
    } else if (atomicSymbol == "Fr") {
        return 87;
    } else if (atomicSymbol == "Ra") {
        return 88;
    } else if (atomicSymbol == "Ac") {
        return 89;
    } else if (atomicSymbol == "Th") {
        return 90;
    } else if (atomicSymbol == "Pa") {
        return 91;
    } else if (atomicSymbol == "U") {
        return 92;
    } else if (atomicSymbol == "Np") {
        return 93;
    } else if (atomicSymbol == "Pu") {
        return 94;
    } else if (atomicSymbol == "Am") {
        return 95;
    } else if (atomicSymbol == "Cm") {
        return 96;
    } else if (atomicSymbol == "Bk") {
        return 97;
    } else if (atomicSymbol == "Cf") {
        return 98;
    } else if (atomicSymbol == "Es") {
        return 99;
    } else if (atomicSymbol == "Fm") {
        return 100;
    } else if (atomicSymbol == "Md") {
        return 101;
    } else if (atomicSymbol == "No") {
        return 102;
    } else if (atomicSymbol == "Lr") {
        return 103;
    } else if (atomicSymbol == "Rf") {
        return 104;
    } else if (atomicSymbol == "Db") {
        return 105;
    } else if (atomicSymbol == "Sg") {
        return 106;
    } else if (atomicSymbol == "Bh") {
        return 107;
    } else if (atomicSymbol == "Hs") {
        return 108;
    } else if (atomicSymbol == "Mt") {
        return 109;
    } else if (atomicSymbol == "Ds") {
        return 110;
    } else if (atomicSymbol == "Rg") {
        return 111;
    } else if (atomicSymbol == "Cn") {
        return 112;
    } else {
        return -1;
    }
}
