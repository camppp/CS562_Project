template <class Op>
inline hb_vector_size_t process(const hb_vector_size_t &o) const
{
    // Create a new vector of the same size as the input vector
    hb_vector_size_t result(o.size());

    // Apply the operation to each element of the input vector
    for (size_t i = 0; i < o.size(); i++)
    {
        result[i] = Op::apply(o[i]);
    }

    return result;
}
