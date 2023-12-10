#include <fcppt/math/vector/object.hpp>
#include <fcppt/math/vector/static.hpp>

template <typename T, typename S1, typename S2>
fcppt::math::vector::static_<T, 3> cross(
    fcppt::math::vector::object<T, 3, S1> const &l, fcppt::math::vector::object<T, 3, S2> const &r)
{
    return fcppt::math::vector::static_<T, 3>(
        l.y() * r.z() - l.z() * r.y(),
        l.z() * r.x() - l.x() * r.z(),
        l.x() * r.y() - l.y() * r.x());
}
