#include <cmath>

class TrkPocaBase {
public:
    TrkPocaBase(double flt1, double flt2, double precision) {
        // Calculate the POCA using the given track parameters and precision
        double x1 = flt1.x();
        double y1 = flt1.y();
        double z1 = flt1.z();
        double x2 = flt2.x();
        double y2 = flt2.y();
        double z2 = flt2.z();
        double dx = x2 - x1;
        double dy = y2 - y1;
        double dz = z2 - z1;
        double d = sqrt(dx * dx + dy * dy + dz * dz);
        double t = d / precision;
        double x = x1 + t * dx;
        double y = y1 + t * dy;
        double z = z1 + t * dz;
        double poca = sqrt(x * x + y * y + z * z);
        // Store the POCA in the class
        _poca = poca;
    }

    double getPoca() const {
        return _poca;
    }

private:
    double _poca;
};
