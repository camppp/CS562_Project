#include <iostream>
#include <cmath>

const float moveMag = 5e-3;
const float diffDeRelEps = 6e-2;
const int repsTot = 10;
const int repsPassReq = 9;
int repsPass = 0;

bool runTest() {
  int passCount = 0;
  for (int i = 1; i <= repsTot; i++) {
    float movementMagnitude = (float)rand() / RAND_MAX * moveMag;
    float relativeDifference = (float)rand() / RAND_MAX * diffDeRelEps;
    if (movementMagnitude < relativeDifference) {
      passCount++;
    }
  }
  if (passCount >= repsPassReq) {
    return true;
  } else {
    return false;
  }
}

int main() {
  bool testPassed = runTest();
  if (testPassed) {
    std::cout << "Test passed!" << std::endl;
  } else {
    std::cout << "Test failed." << std::endl;
  }
  return 0;
}
