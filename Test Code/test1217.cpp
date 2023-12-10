namespace metal {
    /// \cond
    namespace detail {
        template<class num, class... seqs>
        struct transformer_impl {
            template<template<class...> class expr>
            using type = expr<at<seqs, num>...>;
        };

        template<template<class...> class expr, class... seqs>
        struct transformer {
            using type = typename transformer_impl<size_t<0>, seqs...>::template type<expr>;
        };
    }
    /// \endcond
}
