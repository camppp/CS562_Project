template <typename Other>
using greater_than = std::conditional_t<
  (value > Other::value),
  std::true_type, std::false_type>;
