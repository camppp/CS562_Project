#include <string>
#include <boost/optional.hpp>
#include <elle/serialization/SerializerIn.hpp>

class BeyondError {
private:
  std::string error_;
  std::string reason_;
  boost::optional<std::string> name_;

public:
  BeyondError(const std::string& error, const std::string& reason, const boost::optional<std::string>& name)
    : error_(error), reason_(reason), name_(name)
  {}

  BeyondError(elle::serialization::SerializerIn& s)
    : BeyondError(s.deserialize<std::string>("error"),
                  s.deserialize<std::string>("reason"),
                  s.deserialize<boost::optional<std::string>>("name"))
  {}

  std::string name_opt() const
  {
    if (name_) {
      return *name_;
    } else {
      return "No name associated with the error";
    }
  }
};
