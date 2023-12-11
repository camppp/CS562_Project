#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/object.hpp>

template <typename T, typename S1, typename S2>
fcppt::math::vector::static_<T, 3> cross(
    fcppt::math::vector::object<T, 3, S1> const &l,
    fcppt::math::vector::object<T, 3, S2> const &r)
{
    return fcppt::math::vector::static_<T, 3>(
        l.storage().data()[1] * r.storage().data()[2] - l.storage().data()[2] * r.storage().data()[1],
        l.storage().data()[2] * r.storage().data()[0] - l.storage().data()[0] * r.storage().data()[2],
        l.storage().data()[0] * r.storage().data()[1] - l.storage().data()[1] * r.storage().data()[0]);
}