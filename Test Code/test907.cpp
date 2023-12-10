#include <vector>
#include <algorithm>

int calculateDistanceTraveled(const std::vector<int>& speeds, const std::vector<int>& speed_limits) {
  std::vector<int> out;
  for (size_t i = 0; i < speeds.size(); ++i) {
    out.push_back(std::min(speeds[i], speed_limits[i]));
  }
  int totalDistance = 0;
  for (int distance : out) {
    totalDistance += distance;
  }
  return totalDistance;
}
