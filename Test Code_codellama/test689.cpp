#include <boost/hana/define_struct.hpp>
#include <boost/hana/equal.hpp>
#include <boost/hana/members.hpp>
#include <boost/hana/not_equal.hpp>
namespace hana = boost::hana;

struct SomeStruct {
    BOOST_HANA_DEFINE_STRUCT(SomeStruct, (int, x));
};

bool isEqual(const SomeStruct& lhs, const SomeStruct& rhs) {
    return hana::equal(lhs.x, rhs.x);
}
