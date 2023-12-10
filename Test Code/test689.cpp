#include <boost/hana/define_struct.hpp>
#include <boost/hana/equal.hpp>
#include <boost/hana/members.hpp>
#include <boost/hana/not_equal.hpp>
namespace hana = boost::hana;

struct SomeStruct {
    BOOST_HANA_DEFINE_STRUCT(SomeStruct, (int, x));
};

bool isEqual(const SomeStruct& s1, const SomeStruct& s2) {
    return hana::equal(hana::at_key(s1, hana::int_c<0>), hana::at_key(s2, hana::int_c<0>));
}
