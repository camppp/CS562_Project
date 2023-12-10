void handleClientMessage(zmq::socket_t* socket) {
    while (true) {
        zmq::message_t request;
        socket->recv(&request);

        ibinstream m((char*)request.data(), request.size());
        int client_id, target_engine_id;
        m >> client_id;
        m >> target_engine_id;

        // Process the received client_id and target_engine_id
        // Example: Print the received values
        std::cout << "Received client_id: " << client_id << ", target_engine_id: " << target_engine_id << std::endl;
    }
}
