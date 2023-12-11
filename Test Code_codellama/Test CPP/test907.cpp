int calculateDistanceTraveled(const std::vector<int>& speeds, const std::vector<int>& speed_limits) {
  int total_distance = 0;
  for (size_t i = 0; i < speeds.size(); ++i) {
    total_distance += std::min(speeds[i], speed_limits[i]);
  }
  return total_distance;
}
