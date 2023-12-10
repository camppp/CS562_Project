switch (header.command) {
  case kEchoRequest:
    header.command = kEchoResponse;
    header.pid = GetCurrentProcessId();
    WriteAll(handle, &header, sizeof header);
    goto Repeat;
    break;
  case kEchoResponse:
    goto Repeat;
    break;
  case kMessage: {
    uint32_t total_message_bytes = header.message_length;
    size_t count = 0;
    message->flags = 0;
    // Additional processing for kMessage type
    // ...
    break;
  }
  default:
    // Handle unknown message types
    break;
}
