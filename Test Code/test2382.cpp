template <typename T, template <typename...> class Template>
struct is_specialization_of : std::false_type {};

template <template <typename...> class Template, typename... Args>
struct is_specialization_of<Template<Args...>, Template> : std::true_type {};

// Example usage:
// static_assert(is_specialization_of<std::vector<int>, std::vector>::value, "Error: Not a specialization of std::vector");
// static_assert(!is_specialization_of<int, std::vector>::value, "Error: Should not be a specialization of std::vector");
