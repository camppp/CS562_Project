namespace operators {

namespace detail {

template<class ResultType, class SourceOperator, class Operator>
struct lift_traits
{
    typedef rxu::decay_t<ResultType> result_value_type;
    typedef rxu::decay_t<SourceOperator> source_operator_type;
    typedef rxu::decay_t<Operator> operator_type;

    typedef typename source_operator_type::value_type source_value_type;
    typedef typename std::result_of<Operator(source_value_type)>::type result_value_type;
};

} // namespace detail

} // namespace operators
