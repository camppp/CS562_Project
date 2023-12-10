#include <array>

namespace intern {
    template <class T, size_t size, size_t index>
    struct TransformReduce_ {
        static constexpr auto call(const std::array<T, size> &lhs,
                                  const std::array<T, size> &rhs,
                                  const Transformer &transformer,
                                  const Reducer &reducer) {
            return reducer(transformer(lhs[index], rhs[index]),
                           TransformReduce_<T, size, index - 1>::call(lhs, rhs, transformer, reducer));
        }
    };

    template <class T, size_t size>
    struct TransformReduce_<T, size, 0> {
        static constexpr auto call(const std::array<T, size> &lhs,
                                  const std::array<T, size> &rhs,
                                  const Transformer &transformer,
                                  const Reducer &reducer) {
            return reducer(transformer(lhs[0], rhs[0]), T{});
        }
    };
} // namespace intern

template <class T, size_t size, class Transformer, class Reducer>
constexpr auto transform_reduce(const std::array<T, size> &lhs,
                                const std::array<T, size> &rhs,
                                Transformer transformer,
                                Reducer reducer) -> decltype(transformer(lhs[0], rhs[0])) {
    static_assert(size >= 1, "see overloads");
    return intern::TransformReduce_<T, size, size - 1>::call(lhs, rhs, transformer, reducer);
}
