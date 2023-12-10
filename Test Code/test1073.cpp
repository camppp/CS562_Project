// Include necessary headers
#include <zmq.hpp>
#include "your_protocol_buffer_header.h"  // Replace with the actual protocol buffer header

// Function to send a serialized protocol buffer message
void SendSerializedProto(zmq::socket_t& push, const YourProtoBuffer& req, int type, int priority) {
    // Serialize the protocol buffer message
    std::string serialized_msg;
    req.SerializeToString(&serialized_msg);

    // Create a ZeroMQ message and send the serialized message
    zmq::message_t zmq_msg(serialized_msg.size());
    memcpy(zmq_msg.data(), serialized_msg.data(), serialized_msg.size());
    push.send(zmq_msg, zmq::send_flags::none);
}

int main() {
    // Create ZeroMQ context and sockets
    zmq::context_t context(1);
    zmq::socket_t push(context, zmq::socket_type::push);
    push.bind("tcp://*:5555");  // Bind to the specified address

    zmq::socket_t pull(context, zmq::socket_type::pull);
    pull.connect("tcp://localhost:5555");  // Connect to the specified address

    // Create an instance of your protocol buffer message
    YourProtoBuffer req;

    // Call the function to send the serialized protocol buffer message
    SendSerializedProto(push, req, 1, 9);

    // Receive a message using the pull socket
    zmq::message_t msg;
    pull.recv(msg, zmq::recv_flags::none);

    // Process the received message
    std::string received_msg(static_cast<char*>(msg.data()), msg.size());
    // Deserialize the received message into your protocol buffer object
    YourProtoBuffer received_req;
    received_req.ParseFromString(received_msg);

    // Further processing of the received protocol buffer message
    // ...

    return 0;
}
