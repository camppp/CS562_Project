void processRouteError(uint32_t errorType) {
  uint32_t rerrSize;
  NS_LOG_DEBUG("The error type value here " << (uint32_t)errorType);
  if (errorType == 1) {
    // Remove the route error header from the packet and get the error type
    DsrOptionRerrUnreachHeader rerrUnreach;
    // Extract the error type from the route error header
    uint32_t errorType = rerrUnreach.GetErrorType();
    // Remove the route error header from the packet
    rerrUnreach.Remove();
    // Handle the route error of type 1
    handleUnreachableDestination(errorType);
  }
}
