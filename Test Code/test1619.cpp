template <typename T, T V>
struct Value {
  static constexpr T value = V;
};

template <typename T1, typename T2>
using greater_than = std::conditional_t<
  (T1::value > T2::value),
  std::true_type, std::false_type>;
