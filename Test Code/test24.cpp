template <typename T, typename S1, typename S2>
fcppt::math::vector::static_<T, 3> cross(
    fcppt::math::vector::object<T, 3, S1> const &l, fcppt::math::vector::object<T, 3, S2> const &r)
{
  return fcppt::math::vector::static_<T, 3>(
      l[1] * r[2] - l[2] * r[1],
      l[2] * r[0] - l[0] * r[2],
      l[0] * r[1] - l[1] * r[0]);
}
