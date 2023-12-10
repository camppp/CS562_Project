#include <iostream>
#include <zmq.hpp>
#include <ibinstream.hpp>

// Define the message structure
struct Message {
    int client_id;
    int target_engine_id;
};

// Define the server-side message handling logic
void handleMessage(zmq::socket_t* socket_) {
    // Receive the message from the client
    zmq::message_t message;
    socket_->recv(&message);

    // Deserialize the message
    ibinstream stream(message.data(), message.size());
    Message msg;
    stream >> msg;

    // Extract the client_id and target_engine_id from the message
    int client_id = msg.client_id;
    int target_engine_id = msg.target_engine_id;

    // Process the message
    // ...
}
