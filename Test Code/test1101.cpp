#include <type_traits>
#include <string>

namespace traits {
  // Define the type trait to identify string types
  template <typename T>
  struct is_string : std::false_type {};

  template <>
  struct is_string<std::string> : std::true_type {};

  template <>
  struct is_string<const char*> : std::true_type {};

  // Add additional specializations for other string types if needed
}

// Define the meta-function to enable serialization for directly serializable types
template<class T>
using enable_if_is_directly_serializable_t = typename std::enable_if<
  std::is_fundamental<T>::value || traits::is_string<T>::value
>::type;
