RTC::ReturnCode_t RTMtoROS::onStateUpdate(RTC::UniqueId ec_id)
{
  // Perform state update logic here
  std::cout << "State updated for id: " << ec_id.id << std::endl;
  return RTC::RTC_OK; // Assuming state update was successful
}
