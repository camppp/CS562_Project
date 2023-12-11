#include <zmq.hpp>
#include <protocol_buffers.h>

void SendSerializedProto(zmq::socket_t push, const protocol_buffers::Message& req, int type, int priority) {
  // Serialize the protocol buffer message
  std::string serialized_req = req.SerializeAsString();

  // Create a ZeroMQ message from the serialized protocol buffer message
  zmq::message_t msg(serialized_req.size());
  memcpy(msg.data(), serialized_req.data(), serialized_req.size());

  // Send the message using the push socket
  push.send(msg);
}
