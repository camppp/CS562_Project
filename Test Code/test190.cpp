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
  std::vector<double> v1 = {1.0, 2.0, 3.0};
  std::vector<double> v2 = {4.0, 5.0, 6.0};

  double distance = euclideanDistance(v1, v2);

  std::cout << "The Euclidean distance between v1 and v2 is: " << distance << std::endl;

  return 0;
}
