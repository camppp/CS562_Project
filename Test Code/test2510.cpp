#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Vector3 {
public:
    float x, y, z;
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
};

class Atom {
private:
    int atomicNum;
    Vector3 coordinates;

public:
    Atom(int atomicNum, const Vector3& coordinates) : atomicNum(atomicNum), coordinates(coordinates) {}

    static bool isValidAtomicSymbol(const std::string& symbol) {
        // Add logic to validate atomic symbols
        // For example, check against a list of valid symbols
        return true; // Replace with actual validation
    }

    static Atom parseAtom(const std::string& line, int lineNum) {
        std::istringstream iss(line);
        std::vector<std::string> lineSplit(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

        if (lineSplit.size() != 4) {
            std::cerr << "Error in input file: Invalid format on line " << lineNum << std::endl;
            return Atom(-1, Vector3(0, 0, 0)); // Return invalid Atom
        }

        int atomicNum = std::stoi(lineSplit[0]);
        if (!isValidAtomicSymbol(lineSplit[0])) {
            std::cerr << "Error in XYZ reader: Invalid atomic symbol entered." << std::endl;
            std::cerr << "Error occurred on this line: " << line.c_str() << std::endl;
            return Atom(-1, Vector3(0, 0, 0)); // Return invalid Atom
        }

        return Atom(atomicNum, Vector3(std::stof(lineSplit[1]), std::stof(lineSplit[2]), std::stof(lineSplit[3])));
    }
};

void parseInputFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        int lineNum = 1;
        while (std::getline(file, line)) {
            Atom atom = Atom::parseAtom(line, lineNum);
            // Process the atom or handle errors
            if (atom.atomicNum != -1) {
                // Valid atom, process it
            } else {
                // Invalid atom, handle error
            }
            lineNum++;
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
    }
}

int main() {
    parseInputFile("input.txt");
    return 0;
}
