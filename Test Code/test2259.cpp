#include <iostream>
#include <vector>

#define UFSIZE 1000

int union_find[UFSIZE];

void initializeUnionFind() {
  for (auto i = 0; i < UFSIZE; i++) {
    union_find[i] = i;
  }
}

int find(int x) {
  if (union_find[x] == x) {
    return x;
  }
  return union_find[x] = find(union_find[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) {
    union_find[x] = y;
  }
}

long long C(int n, int k) {
  initializeUnionFind();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      merge(j, j + 1);
    }
  }
  for (int i = 1; i <= k; i++) {
    merge(i, i + 1);
  }
  long long result = 1;
  for (int i = 1; i <= n; i++) {
    if (find(i) == i) {
      result *= 2;
    }
  }
  return result;
}

int main() {
  int n = 5;
  int k = 2;
  std::cout << "Number of combinations (n choose k): " << C(n, k) << std::endl;
  return 0;
}
