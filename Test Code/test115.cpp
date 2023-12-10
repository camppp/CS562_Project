#include <algorithm>
#include <cmath>

class FinancialProcess {
public:
    // Other methods and members of the FinancialProcess class

    // Function to calculate the minimum and maximum values of the process
    void calculateMinMax() {
        const Real mp = (mandatoryPoint != Null<Real>()) ? mandatoryPoint : process->x0();

        const Real qMin = std::min(std::min(mp, process->x0()),
            process->evolve(0, process->x0(), t, InverseCumulativeNormal()(eps)));
        const Real qMax = std::max(std::max(mp, process->x0()),
            process->evolve(0, process->x0(), t, InverseCumulativeNormal()(1-eps)));

        const Real dp = (1-2*eps)/(size-1);
        Real p = eps;
        locations_[0] += qMin;

        // Use qMin and qMax for further processing or store them as needed
    }
};
