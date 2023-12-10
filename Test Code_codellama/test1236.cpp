#include <boost/uuid/sha1.hpp>
#include <string>

std::string calculateSHA1(const std::string& input) {
    boost::uuids::sha1 hash;
    hash.process_bytes(input.data(), input.size());
    return hash.to_string();
}
