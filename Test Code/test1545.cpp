void processClientData(const QByteArray& data) {
    // Extract timestamp and message from the received data
    QString timestamp = data.mid(0, 19);
    QString message = data.mid(20);

    // Process the data to display the timestamp and message
    QString displayText = QString("Received message from client: %1 at %2").arg(message).arg(timestamp);
    qDebug() << displayText;
}
