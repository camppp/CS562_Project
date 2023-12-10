void Server::incomingMessage()
{
    // Receive the incoming message from the socket
    QByteArray message = socket->readAll();

    // Broadcast the message to all connected clients except the sender
    for (auto client : clients) {
        if (client != socket) {
            client->write(message);
        }
    }

    // Delete the socket after processing the message
    socket->deleteLater();
}
