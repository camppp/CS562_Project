#include <numeric>

template <>
std::map<ccl_coll_allreduce_algo, std::string>
    ccl_algorithm_selector_helper<ccl_coll_allreduce_algo>::algo_names = {
        std::make_pair(ccl_coll_allreduce_direct, "direct"),
        std::make_pair(ccl_coll_allreduce_recursive_doubling, "recursive_doubling"),
        std::make_pair(ccl_coll_allreduce_ring, "ring"),
        std::make_pair(ccl_coll_allreduce_starlike, "starlike"),
        std::make_pair(ccl_coll_allreduce_naive, "naive"),
        std::make_pair(ccl_coll_allreduce_rabenseifner, "rabenseifner")
    };
