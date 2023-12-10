template <typename Frame>
struct get_function_annotation<pika::detail::dataflow_finalization<Frame>>
{
    using function_type = decltype(std::declval<Frame>().get_function());

    static constexpr auto call(const pika::detail::dataflow_finalization<Frame>& df)
    {
        return df.get_function().get_annotation();
    }
};
