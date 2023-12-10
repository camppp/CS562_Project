enum class ImplementationMethod { Method1, Method2 };

bool compareBitwiseResult(int d, ImplementationMethod im) {
  return static_cast<ImplementationMethod>(d & 1) == im;
}

int main() {
  bool result1 = compareBitwiseResult(5, ImplementationMethod::Method1); // Result: true
  bool result2 = compareBitwiseResult(5, ImplementationMethod::Method2); // Result: false
}
