void DiscardRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // Serialize the message field
  target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(1, this->message(), target);

  // Serialize the unknown fields
  target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
      _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(
          target));

  return target;
}
