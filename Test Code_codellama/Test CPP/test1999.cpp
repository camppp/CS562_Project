void processHeaders(Headers& clientToServer, Headers& serverToClient) {
    // Forward all headers from the client to the remote server, except for the "Host" header
    for (auto& header : clientToServer) {
        if (header.first != "Host") {
            serverToClient.add(header.first, header.second);
        }
    }

    // Forward all headers from the remote server to the client, except for the "Set-Cookie" header
    for (auto& header : serverToClient) {
        if (header.first != "Set-Cookie") {
            clientToServer.add(header.first, header.second);
        }
    }
}
