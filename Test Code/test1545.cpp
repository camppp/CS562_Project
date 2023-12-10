#include <iostream>
#include <QDateTime>

void processClientData(const QByteArray& data) {
    // Assuming the data format is "timestamp\nmessage"
    QString strData(data);
    QStringList parts = strData.split("\n");
    
    if (parts.size() == 2) {
        QString timestamp = parts[0];
        QString message = parts[1];
        
        // Display the timestamp and message
        QDateTime dateTime = QDateTime::fromString(timestamp, "yyyy-MM-dd hh:mm:ss");
        std::cout << "Received at " << dateTime.toString().toStdString() << ": " << message.toStdString() << std::endl;
    } else {
        std::cerr << "Invalid data format" << std::endl;
    }
}
