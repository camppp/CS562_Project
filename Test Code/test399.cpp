rmw_ret_t process_service_request(
  rmw_service_t *service_handle,
  const char *implementation_identifier,
  void *ros_request_header,
  void *ros_response
) {
  RMW_CHECK_TYPE_IDENTIFIERS_MATCH(
    service_handle,
    implementation_identifier, toc_coredx_identifier,
    return RMW_RET_ERROR)

  if (!ros_request_header) {
    RMW_SET_ERROR_MSG("ros request header handle is null");
    return RMW_RET_ERROR;
  }
  if (!ros_response) {
    RMW_SET_ERROR_MSG("ros response handle is null");
    return RMW_RET_ERROR;
  }

  return RMW_RET_OK;
}
