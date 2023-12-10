#include <iostream>
#include <vector>

class Histogram {
private:
    const double &xlo;
    const double &xhi;
    const int &nbins;
    double binWidth;
    std::vector<int> bins;

    int getBinIndex(const double &x) {
        return static_cast<int>((x - xlo) / binWidth);
    }

public:
    Histogram(const double &xlo, const double &xhi, const int &nbins)
        : xlo(xlo), xhi(xhi), nbins(nbins), bins(nbins, 0) {
        binWidth = (xhi - xlo) / nbins;
    }

    void addDataPoint(const double &x) {
        int binIndex = getBinIndex(x);
        if (binIndex >= 0 && binIndex < nbins) {
            bins[binIndex]++;
        }
    }

    int getBinCount(const int &binIndex) {
        if (binIndex >= 0 && binIndex < nbins) {
            return bins[binIndex];
        }
        return 0;
    }
};

int main() {
    Histogram hist(0.0, 10.0, 5);
    hist.addDataPoint(2.5);
    hist.addDataPoint(7.8);
    hist.addDataPoint(11.0);
    std::cout << "Bin 2 count: " << hist.getBinCount(2) << std::endl;  // Output: Bin 2 count: 1
    std::cout << "Bin 4 count: " << hist.getBinCount(4) << std::endl;  // Output: Bin 4 count: 0
    return 0;
}
