#include <iostream>

int customRandom(int seed, int a, int c, int m) {
  int x = seed;
  int sequence[10];
  for (int i = 0; i < 10; i++) {
    x = (a * x + c) % m;
    sequence[i] = x;
  }
  return sequence;
}

int main() {
  int seed = 3;
  int a = 7;
  int c = 3;
  int m = 10;
  int* sequence = customRandom(seed, a, c, m);
  for (int i = 0; i < 10; i++) {
    std::cout << sequence[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
