#include <iostream>
#include <vector>
#include <cmath>

double euclideanDistance(const std::vector<double>& v1, const std::vector<double>& v2) {
  double ss = 0.0;
  for (int i = 0; i < v1.size(); i++) {
    ss += (v1.at(i) - v2.at(i)) * (v1.at(i) - v2.at(i));
  }
  return sqrt(ss);
}

int main() {
  // Example usage
  std::vector<double> vector1 = {1.0, 2.0, 3.0};
  std::vector<double> vector2 = {4.0, 5.0, 6.0};

  double distance = euclideanDistance(vector1, vector2);
  std::cout << "Euclidean distance between vector1 and vector2: " << distance << std::endl;

  return 0;
}
