void Server::incomingMessage()
{
    // Read the incoming message from the socket
    QByteArray message = socket->readAll();

    // Iterate through all connected clients and relay the message
    for (QTcpSocket *client : clients) {
        if (client != socket) {  // Exclude the sender
            qint64 bytesWritten = client->write(message);
            if (bytesWritten == -1) {
                // Handle error writing to client
                qDebug() << "Error writing to client";
            }
        }
    }

    // Check for any errors or disconnections
    if (socket->state() == QAbstractSocket::UnconnectedState) {
        // Handle client disconnection
        clients.removeOne(socket);
        socket->deleteLater();
    }
}
