#include <vector>
#include <cmath>

class CaloRegion {
 public:
  double hwPt() const { return hwPt_; }

 private:
  double hwPt_;
};

double totalPhysicalEtSum(const std::vector<CaloRegion>& regions) {
  double totalEt = 0;
  for (const auto& region : regions) {
    totalEt += region.hwPt() * cosPhi[region.hwPt()];
  }
  return totalEt;
}
