::google::protobuf::uint8* DiscardRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string message = 1;
  if (has_message()) {
    // Get the length of the message
    const int message_length = message().size();
    
    // Write the tag for the 'message' field (field number 1, wire type 2 for length-delimited)
    *target++ = 0x0A;  // Field number 1, wire type 2
    
    // Write the length of the message as a varint
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
        message_length, target);
    
    // Write the message data
    target = ::google::protobuf::io::CodedOutputStream::WriteStringToArray(
        message(), target);
  }
  return target;
}
