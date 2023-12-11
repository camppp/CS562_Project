#include <QApplication>
#include <QDateTime>
#include <QUuid>
#include <iostream>

class UniqueIdentifierGenerator {
public:
    QString generateIdentifier() {
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString timestamp = currentDateTime.toString("yyyy-MM-ddThh:mm:ss");
        QString uuid = QUuid::createUuid().toString();
        return timestamp + " " + uuid;
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    UniqueIdentifierGenerator generator;
    QString uniqueIdentifier = generator.generateIdentifier();
    std::cout << uniqueIdentifier.toStdString() << std::endl;
    return app.exec();
}
