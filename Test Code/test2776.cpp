#include <string>
#include <boost/optional.hpp>

class BeyondError {
public:
    BeyondError(elle::serialization::SerializerIn& s)
        : error_(s.deserialize<std::string>("error")),
          reason_(s.deserialize<std::string>("reason")),
          name_(s.deserialize<boost::optional<std::string>>("name"))
    {}

    std::string name_opt() const {
        return name_.value_or("");
    }

private:
    std::string error_;
    std::string reason_;
    boost::optional<std::string> name_;
};
