namespace metal {
namespace detail {

template<template<class...> class Expr, class... Seqs>
struct transformer {
    using type = Expr<typename Seqs::template at<std::size_t>::type...>;
};

template<template<class...> class Expr, class... Seqs>
using transformer_t = typename transformer<Expr, Seqs...>::type;

} // namespace detail
} // namespace metal
