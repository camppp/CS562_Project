#include <iostream>

int findPythagoreanTripletProduct() {
  int a = 0, b = 0, c = 0;
  for (int i = 1; i < 1000; i++) {
    for (int j = i + 1; j < 1000; j++) {
      if (i * i + j * j == (1000 - i - j) * (1000 - i - j)) {
        a = i;
        b = j;
        c = 1000 - i - j;
        break;
      }
    }
    if (a != 0 && b != 0 && c != 0) {
      break;
    }
  }
  if (a == 0 || b == 0 || c == 0) {
    return 0;
  }
  return a * b * c;
}

int main() {
  std::cout << findPythagoreanTripletProduct() << std::endl;
  return 0;
}
