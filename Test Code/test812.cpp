#include <iostream>
#include <fstream>
#include <complex>
#include <cmath>

class RawFileSource {
private:
    std::ifstream file;

public:
    RawFileSource(const std::string& filename) : file(filename, std::ios::binary) {}

    ~RawFileSource() {
        if (file.is_open()) {
            file.close();
        }
    }

    std::complex<double> tick() {
        short i, q;
        file.read((char*) &i, sizeof(short));
        file.read((char*) &q, sizeof(short));
        double realI = i / 32767.0;
        double realQ = q / 32767.0;
        return std::complex<double>(realI, realQ);
    }
};

void processSignal(const std::string& filename) {
    RawFileSource source(filename);
    std::complex<double> complexNumber;
    double sumMagnitude = 0.0;
    int count = 0;

    while (true) {
        complexNumber = source.tick();
        if (source.eof()) {
            break;
        }
        double magnitude = std::abs(complexNumber);
        sumMagnitude += magnitude;
        count++;
    }

    if (count > 0) {
        double averageMagnitude = sumMagnitude / count;
        std::cout << std::fixed << std::setprecision(6) << averageMagnitude << std::endl;
    } else {
        std::cout << "No data found in the file." << std::endl;
    }
}

int main() {
    processSignal("input.raw");
    return 0;
}
