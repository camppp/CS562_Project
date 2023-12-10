template <class Op>
inline hb_vector_size_t process(const hb_vector_size_t &o) const
{
  hb_vector_size_t r; // Initialize the result vector
  for (unsigned int i = 0; i < ARRAY_LENGTH(v); i++)
  {
    // Apply the operation to each element and store the result in the result vector
    r[i] = Op()(o[i]);
  }
  return r; // Return the resulting vector
}
