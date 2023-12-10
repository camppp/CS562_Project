#include <iostream>

namespace RTC {
  enum ReturnCode_t {
    RTC_OK,
    RTC_ERROR
  };

  struct UniqueId {
    int id;
  };
}

class RTMtoROS {
public:
  RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);
};

RTC::ReturnCode_t RTMtoROS::onStateUpdate(RTC::UniqueId ec_id)
{
  // Your implementation goes here
  std::cout << "State updated: " << ec_id.id << std::endl;
  return RTC_OK;
}
