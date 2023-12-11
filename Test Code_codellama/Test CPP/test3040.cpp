#include <boost/tti/has_data.hpp>

template <typename T>
struct has_member_AnInt : boost::tti::has_data<T, "AnInt">::type {};
