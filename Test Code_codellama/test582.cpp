#include <iostream>

double calculateCrossSectionalArea(double Hm, double Hpf, double fa_int, double L, double D) {
  if (D == 0) {
    return 0;
  }

  return (Hm + Hpf + fa_int) * L / D;
}

int main() {
  double Hm = 10.0;
  double Hpf = 5.0;
  double fa_int = 2.0;
  double L = 10.0;
  double D = 5.0;

  double area = calculateCrossSectionalArea(Hm, Hpf, fa_int, L, D);

  std::cout << "Cross-sectional area: " << area << std::endl;

  return 0;
}
