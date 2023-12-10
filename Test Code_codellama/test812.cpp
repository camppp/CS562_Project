#include <iostream>
#include <fstream>
#include <cmath>

class RawFileSource {
public:
    RawFileSource(const std::string& filename) {
        file.open(filename, std::ios::in | std::ios::binary);
    }

    ~RawFileSource() {
        file.close();
    }

    void tick() {
        short int realI, realQ;
        file.read((char*)&realI, sizeof(short int));
        file.read((char*)&realQ, sizeof(short int));
        complexNumber = std::complex<double>(realI / 32767.0, realQ / 32767.0);
    }

private:
    std::ifstream file;
    std::complex<double> complexNumber;
};

void processSignal(const std::string& filename) {
    RawFileSource source(filename);
    std::vector<std::complex<double>> complexNumbers;

    while (source.tick()) {
        complexNumbers.push_back(source.complexNumber);
    }

    double averageMagnitude = 0.0;
    for (const auto& complexNumber : complexNumbers) {
        averageMagnitude += std::abs(complexNumber);
    }
    averageMagnitude /= complexNumbers.size();

    std::cout << "Average magnitude: " << std::fixed << std::setprecision(6) << averageMagnitude << std::endl;
}
