namespace operators::detail {
template<typename ResultType, typename SourceOperator, typename Operator>
struct lift_traits {
    using result_value_type = ResultType;
    using source_value_type = decltype(std::declval<SourceOperator>()(std::declval<Operator>()));
};
}
