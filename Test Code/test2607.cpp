void processRouteError(uint32_t errorType) {
  uint32_t rerrSize;
  NS_LOG_DEBUG("The error type value here " << (uint32_t)errorType);
  if (errorType == 1) {
    // Remove the route error header from the packet and get the error type
    DsrOptionRerrUnreachHeader rerrUnreach;
    // Your code to handle the route error of type 1
    // Example: Log the unreachable IP address or take appropriate action
    // For example:
    NS_LOG_DEBUG("Handling route error: Unreachable IP address");
    // Further processing or action based on the unreachable IP address
  }
}
