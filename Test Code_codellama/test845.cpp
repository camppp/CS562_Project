int calculateValue(int s, int min1, int min2_10, int min11) {
  for (int i = 2; i <= 10; i++) {
    if (s < min1 + min2_10 * (i - 1)) {
      return i - 1;
    }
  }
  return 10 + (s - min1 - min2_10 * 9) / min11;
}
