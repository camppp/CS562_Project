#include <iostream>
#include <type_traits>

namespace detail {
  template <typename T>
  struct is_iterator {
    using yes = char;
    using no = struct { char _[2]; };

    template <typename C>
    static yes test(typename std::iterator_traits<C>::iterator_category*);

    template <typename>
    static no test(...);

    static const bool value = sizeof(test<T>(0)) == sizeof(yes);
  };
}

template <typename T, typename = void>
struct value_of;

template <typename T>
struct value_of<T, typename std::enable_if<detail::is_iterator<T>::value>::type> {
  using type = typename std::iterator_traits<T>::value_type;
};

int main() {
  using Iter = std::vector<int>::iterator;
  using ValueType = typename value_of<Iter>::type;
  std::cout << "Value type of the iterator: " << typeid(ValueType).name() << std::endl;
  return 0;
}
