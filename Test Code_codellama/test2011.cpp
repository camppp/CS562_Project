#include <concepts>

template <typename T>
concept IsArgumentProviderOfExpandables = requires(T t) {
    { t.expand() } -> std::vector<std::string>;
};
