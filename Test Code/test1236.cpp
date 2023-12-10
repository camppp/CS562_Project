#include <boost/uuid/sha1.hpp>
#include <boost/algorithm/hex.hpp>

std::string calculateSHA1(const std::string& input) {
    boost::uuids::detail::sha1 sha1;
    sha1.process_bytes(input.data(), input.size());

    unsigned int digest[5];
    sha1.get_digest(digest);

    std::string hash;
    for (int i = 0; i < 5; ++i) {
        std::string hexStr;
        boost::algorithm::hex(std::to_string(digest[i]), std::back_inserter(hexStr));
        hash += hexStr;
    }

    return hash;
}
