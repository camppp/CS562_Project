#include <iostream>
using namespace std;

int customInput() {
  int n = 0;
  bool negative = false;
  int c = getchar();
  while ((c < '0' || c > '9') && c != '-') {
    c = getchar();
  }
  if (c == '-') {
    negative = true;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    n = n * 10 + (c - '0');
    c = getchar();
  }
  return (negative ? -n : n);
}
